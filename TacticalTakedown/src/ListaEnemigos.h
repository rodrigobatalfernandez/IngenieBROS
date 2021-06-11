#pragma once
#include "Enemigo.h"
#include "ListaDisparos.h"
#include "Mapa.h"
#define MAX_ENEMIGOS 25

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
	void crearEnemigo(float x, float y, float ori = 0, int tipo = 1);
	void crearEnemigo(Vector2D a);
	void cargarEnem(int nivel);


	void dibuja();
	void mueve(Vector2D Objetivo, Mapa& mapa, float t);
	void dispara(Vector2D Objetivo, ListaDisparos& listadisparos, Mapa& mapa);
};
