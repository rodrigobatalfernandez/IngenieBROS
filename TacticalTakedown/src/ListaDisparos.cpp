#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

bool ListaDisparos::agregar(Disparo* d) {
	if (numero < MAX_DISPAROS) {
		for (int i = 0; i < numero; i++) {
			if (d == lista[i])
				return false; // el disparo ya se encuentra en la lista
		}
		lista[numero++] = d; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;	// operación exitosa
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

void ListaDisparos::dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

Disparo* ListaDisparos::colision(Pared p) {
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
			return lista[i];
	}
	return 0;
}