#include"ListaParedes.h"
#include "Interaccion.h"

ListaParedes::ListaParedes()
{
	numero = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		lista[i] = 0;
}

bool ListaParedes::agregar(Pared* p)
{
	if (numero < MAX_PAREDES) {
		for (int i = 0; i < numero; i++) {
			if (p == lista[i])
				return false; // la pared ya se encuentra en la lista
		}
		lista[numero++] = p; // �ltimo puesto sin rellenar
	}
	else
		return false; // capacidad m�xima alcanzada
	return true;	// operaci�n exitosa
}

void ListaParedes::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaParedes::colision(Disparo d)
{
	for (int i = 0; i < numero; i++)
		Interaccion::colision(d,*(lista[i]));
}

void ListaParedes::colision(Jugador j)
{
	for (int i = 0; i < numero; i++)
		Interaccion::colision(j, *(lista[i]));
}

void ListaParedes::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}