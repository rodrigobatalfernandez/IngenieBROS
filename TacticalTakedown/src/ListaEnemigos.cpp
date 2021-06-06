#include "ListaEnemigos.h"

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
		lista[numero++] = e; // �ltimo puesto sin rellenar
	}
	else
		return false; // capacidad m�xima alcanzada
	return true;	// operaci�n exitosa
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
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
		}
	}
}

void ListaEnemigos::dispara(Vector2D Objetivo, ListaDisparos& listadisparos)
{
	for (int i = 0; i < numero; i++)
		lista[i]->dispara(Objetivo, listadisparos);
}