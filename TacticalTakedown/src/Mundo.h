#pragma once
#include "ETSIDI.H"
#include "Vector2D.h"

#include "Camara.h"
#include "ListaDisparos.h"
#include "Mapa.h"
#include "Interaccion.h"
#include "ListaEnemigos.h"


class Mundo
{
private:
	Camara camara;
	Jugador jugador;
	ListaEnemigos enemigos;
	ListaDisparos disparos, disparos_enemigos;
	Mapa mapa;

	int nivel = 0;
	int vida = 4;
	int abatidos;

public:
	~Mundo();
	void inicializa();
	void mueve();
	void dibuja();

	void teclaAbajo(unsigned char key);
	void teclaArriba(unsigned char key);
	void teclaEspecialAbajo(unsigned char key);
	void teclaEspecialArriba(unsigned char key);
	Vector2D getCam() { return camara.getPos(); }
	int getNum() { return nivel; }
	bool cargarNivel();

	void musica();
};