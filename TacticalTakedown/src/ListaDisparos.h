#pragma once

#define MAX_DISPAROS 100
#include "Disparo.h"

class ListaDisparos
{
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos();
	virtual ~ListaDisparos(){ destruirContenido(); }
	int getNumero() { return numero; }
	Disparo* operator [](int i);

	bool agregar(Disparo* d);
	void eliminar(int index);
	void eliminar(Disparo* d);
	void destruirContenido();

	void mueve(float t);
	void dibuja(bool textura=0);
};