#pragma once
#define MAX_PAREDES 100000
#include"Disparo.h"
#include "Mapa.h"
#include "Jugador.h"
#include "Pared.h"

class ListaParedes
{
public:
	ListaParedes();
	//virtual ~ListaParedes();
private:
	Pared* lista[MAX_PAREDES];
	int numero;
public:
	bool agregar(Pared* e);
	void dibuja();
	void colision(Disparo d);
	void colision(Jugador j);
	void destruirContenido();
	//void eliminar(int index);
	//void eliminar(Pared* e);
};