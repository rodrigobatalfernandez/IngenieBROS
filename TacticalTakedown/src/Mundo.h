#pragma once
#include "ETSIDI.H"
#include "Vector2D.h"

#include "Camara.h"
#include "ListaDisparos.h"
#include "Mapa.h"
#include "Interaccion.h"
#include "ListaEnemigos.h"

#define VIDAS_INI 5
#define VIDAS_NIVEL 1

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
	int nivel=0;
	int vida=VIDAS_INI;
	int abatidos=0;

	//Para la reparación
	bool curado = false;
	bool recargado = false;

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
	void sumaVida() { vida += 2; }
	bool getCura() { return curado; }
	void setCura(bool cura) { curado = cura; }
	void recarga() { jugador.Cooldown(1); }
	bool getRec() { return recargado; }
	void setRec(bool rec) { recargado = rec; }


	bool cargarNivel();
	void dibuja_corazones();
};