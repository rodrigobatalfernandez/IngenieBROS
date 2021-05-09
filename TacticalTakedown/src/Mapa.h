#pragma once
#include "Pared.h"


class Mapa {
private:
	Pared borde_arriba, borde_abajo, borde_izq, borde_dcha;
public:
	Mapa();
	//virtual ~Mapa();
	void dibuja();
	void copia_nivel1();
	void textura(int fil, int col, float altura, char const* cadena1);

	friend class Interaccion;
};