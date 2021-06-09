#pragma once
#include "Enemigo.h"
#include "Torreta.h"
#include "ListaDisparos.h"
#include "Mapa.h"
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
	void crear(float x, float y);
	void crear(Vector2D a);
	void crearTorreta(float x, float y);


	void dibuja();
	void mueve(Vector2D Objetivo, Mapa& mapa, float t);
	void dispara(Vector2D Objetivo, ListaDisparos& listadisparos, Mapa& mapa);
};
