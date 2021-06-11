#pragma once

#define MAX_DISPAROS 100
//#include "Interaccion.h"
#include "Disparo.h"
#include "Pared.h"
//#include "ListaParedes.h"

class ListaDisparos
{
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos();
	//virtual ~ListaDisparos();
	int getNumero() { return numero; }
	Disparo* operator [](int i);

	bool agregar(Disparo* d);
	void eliminar(int index);
	void eliminar(Disparo* d);
	void destruirContenido();

	void mueve(float t);
	void dibuja(bool textura=0);

	Disparo* colision(Pared p);
};