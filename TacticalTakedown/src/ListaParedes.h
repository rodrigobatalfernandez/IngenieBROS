#pragma once
#include "Disparo.h"
#include "Jugador.h"
#include "Pared.h"
#define MAX_PAREDES 100000

class ListaParedes
{
private:
	Pared* lista[MAX_PAREDES];
	int numero;

public:
	ListaParedes();
	//virtual ~ListaParedes();
	bool agregar(Pared* e);
	void dibuja();
	void colision(Disparo d);
	void colision(Jugador j);
	void destruirContenido();
	//void eliminar(int index);
	//void eliminar(Pared* e);
	Pared* operator [](int i);
};