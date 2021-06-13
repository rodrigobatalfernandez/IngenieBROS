#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = nullptr;
}

bool ListaDisparos::agregar(Disparo* d) {
	if (numero < MAX_DISPAROS) {
		for (int i = 0; i < numero; i++) {
			if (d == lista[i])
				return false; // el disparo ya se encuentra en la lista
		}
		lista[numero++] = d; // último puesto sin rellenar
		lista[numero]->sonido_disparo_inicio();
		return true;
	}
	return false; // capacidad máxima alcanzada
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}

void ListaDisparos::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucción de todos los disparos de la lista
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaDisparos::mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja(bool textura) {
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja(textura);
}

Disparo* ListaDisparos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

Disparo* ListaDisparos::colision(Pared p) {
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), p)) {
			lista[i]->sonido_disparo_impacto();
			return lista[i];
		}
	}
	return 0;
}