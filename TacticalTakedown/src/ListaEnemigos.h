#pragma once
#include "Enemigo.h"
#include "Torreta.h"
#include "ListaDisparos.h"
#define MAX_ENEMIGOS 100

class ListaEnemigos
{
private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	int getNumero() { return numero; }
	Enemigo* operator [](int i);

	bool agregar(Enemigo* e);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);

	void dibuja();
	void mueve(float t);
	void persiguePunto(Vector2D Objetivo);
	void dispara(Vector2D Objetivo, ListaDisparos& listadisparos);
};
