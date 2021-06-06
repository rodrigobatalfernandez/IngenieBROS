#pragma once
#include "Pared.h"
//#include "ListaParedes.h"
#include "Enemigo.h"
#include "ListaDisparos.h"
#define MAX_PAREDES 100000


class Mapa {
private: //Para incluir los bordes en lista paredes necesitan ser punteros (Pared*)
public:
	Pared pared[MAX_PAREDES];//borde_arriba, borde_abajo, borde_izq, borde_dcha;
	//ListaParedes paredes;
public:
	Mapa();
	//virtual ~Mapa();
	void dibuja(Jugador& jugador, Enemigo& enemigo); //falta , ListaDisparos& disparos
	void copia_nivel1();
	void textura(int fil, int col, float altura, char const* cadena1);
	//void cargarBordes(Jugador& jugador);

	friend class Interaccion;
};