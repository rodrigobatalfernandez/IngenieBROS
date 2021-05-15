#pragma once
#include "Enemigo.h"
#define MAX_ENEMIGOS 100

class ListaEnemigos
{
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();

	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);
	Enemigo* operator [](int i);
	int getNumero() { return numero; }

	void persiguePunto(Vector2D Objetivo); //Recive un punto y lo sigue



private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListaTorres 
{
public:
	ListaTorres();
	virtual ~ListaTorres();

	bool agregar(Enemigo* e);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);
	Enemigo* operator [](int i);
	int getNumero() { return numero; }

	void miraPunto(Vector2D Objetivo); //Recive un punto y lo mira

private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
};
