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
	//Objetos y Listas
	Camara camara;
	Jugador jugador;
	ListaEnemigos enemigos;
	ListaDisparos disparos, disparos_enemigos;
	Mapa mapa;

	//Contadores
	int nivel = 0;
	int vida = 6;
	int abatidos = 0;

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
	int getVida() { return vida; }
	int getAbatidos() { return abatidos; }
	void setColor(int color) { jugador.setColor(color); }
	int getEnem() { return enemigos.getNumero(); }

	bool cargarNivel();
	void dibuja_corazones();
};