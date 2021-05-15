#pragma once

#define MAX_DISPAROS 10
#include "Interaccion.h"
#include "Disparo.h"
#include "Pared.h"
#include "ListaParedes.h"

class ListaDisparos
{
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos();
	//virtual ~ListaDisparos();
	bool agregar(Disparo* d);
	void eliminar(int index);
	void eliminar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();

	Disparo* colision(Pared p);
};