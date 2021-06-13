#include "ListaEnemigos.h"
#include "Torreta.h"
#include "Lapa.h"

struct genEnem
{
	float x;
	float y;
	float ori;		//ori ==0->derecha,ori ==90->arriba,ori ==180->izquierda,ori ==270->abajo
	int tipo;
};


ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = nullptr;
}

ListaEnemigos::~ListaEnemigos(){}

bool ListaEnemigos::agregar(Enemigo* e)
{
	if (numero < MAX_ENEMIGOS) {
		for (int i = 0; i < numero; i++) {
			if (e == lista[i])
				return false; // el disparo ya se encuentra en la lista
		}
		lista[numero++] = e; // último puesto sin rellenar
		return true;	// operación exitosa

	}
	return false; // capacidad máxima alcanzada
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

void ListaEnemigos::crearEnemigo(float x, float y,float ori, int tipo)
{
	if (tipo == 1) {
		Enemigo* e = new Enemigo();
		e->setPos(x, y);
		e->setOri(ori);
		agregar(e);
	}
	else if (tipo == 2) {
		Torreta* e = new Torreta();
		e->setPos(x, y);
		e->setOri(ori);
		agregar(e);
	}
	else if (tipo == 3) {
		Lapa* e = new Lapa();
		e->setPos(x, y);
		e->setOri(ori);
		agregar(e);
	}

}

void ListaEnemigos::crearEnemigo(Vector2D a)
{
	Enemigo* e = new Enemigo();
	e->setPos(a.x, a.y);
	agregar(e);
}

void ListaEnemigos::cargarEnem(int nivel)
{
	//posible implementacion con for de rango
	if (nivel == 1)
	{
		genEnem matN1[] = {
			//{-7.5,12.7,0,1},
			//{-7.5,42.7,0,1},
			//{-7.5,72.7,0,1},
			//{-7.5,102.7,0,1},
			//{82.5,12.7,180,1},
			//{82.5,42.7,180,1},
			//{82.5,72.7,180,1},
			//{82.5,102.7,180,1},
			//{17.5,107.5,270,2},
			//{57.5,107.5,270,2},
			{22.5, 14,90,3},
			//{52.5, 14,90,3},

		};
		for (int i = 0; i < (sizeof(matN1)/sizeof(genEnem)); i++)
		{
			crearEnemigo(matN1[i].x, matN1[i].y, matN1[i].ori, matN1[i].tipo);
		}
	}
	else if (nivel == 2) {

		genEnem matN1[] = {
			{-7.5,12.7,0,1},
			{-7.5,42.7,0,1},
			{-7.5,72.7,0,1},
			{-7.5,102.7,0,1},
			{82.5,12.7,180,1},
			{82.5,42.7,180,1},
			{82.5,72.7,180,1},
			{82.5,102.7,180,1},
			{17.5,107.5,270,2},
			{57.5,107.5,270,2},
			{22.5, 14,90,3},
			{52.5, 14,90,3},

		};
		for (int i = 0; i < (sizeof(matN1) / sizeof(genEnem)); i++)
		{
			crearEnemigo(matN1[i].x, matN1[i].y, matN1[i].ori, matN1[i].tipo);
		}
	}
	else if (nivel == 3) {

		genEnem matN1[] = {
			{-7.5,12.7,0,1},
			{-7.5,42.7,0,1},
			{-7.5,72.7,0,1},
			{-7.5,102.7,0,1},
			{82.5,12.7,180,1},
			{82.5,42.7,180,1},
			{82.5,72.7,180,1},
			{82.5,102.7,180,1},
			{17.5,107.5,270,2},
			{57.5,107.5,270,2},
			{22.5, 14,90,3},
			{52.5, 14,90,3},

		};
		for (int i = 0; i < (sizeof(matN1) / sizeof(genEnem)); i++)
		{
			crearEnemigo(matN1[i].x, matN1[i].y, matN1[i].ori, matN1[i].tipo);
		}
	}
}

Enemigo* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaEnemigos::mueve(Vector2D Objetivo, Mapa& mapa, float t)
{
	for (int i = 0; i < numero; i++) {
		bool aux = false;
		for (int j = 0; j < mapa.getNumero(); j++) {
			Pared p = *mapa[j];
			if (p.obstaculiza(lista[i]->getPos(), Objetivo))
				aux = true;
		}
		if (!aux) {
			lista[i]->persiguePunto(Objetivo);
			lista[i]->mueve(t);
			lista[i]->resCoolMov();
		}
		else if(lista[i]->getCoolMov() >= 0)
		{
			lista[i]->persiguePunto(Objetivo);
			lista[i]->mueve(t);
			lista[i]->redCoolMov();
		}
	}
}

void ListaEnemigos::dispara(Vector2D Objetivo, ListaDisparos& listadisparos, Mapa& mapa)
{
	for (int i = 0; i < numero; i++) {
		bool aux = false;
		for (int j = 0; j < mapa.getNumero(); j++) {
			Pared p = *mapa[j];
			if (p.obstaculiza(lista[i]->getPos(), Objetivo))
				aux = true;
		}
		if (!aux || lista[i]->getCoolMov() >= 0)
		{
			lista[i]->dispara(Objetivo, listadisparos);
		}
	}
}