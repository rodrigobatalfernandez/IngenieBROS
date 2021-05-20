#pragma once
#include "Pared.h"
#include "ListaParedes.h"


class Mapa {
private: //Para incluir los bordes en lista paredes necesitan ser punteros (Pared*)
	Pared pared[4];//borde_arriba, borde_abajo, borde_izq, borde_dcha;
	//ListaParedes paredes;
public:
	Mapa();
	//virtual ~Mapa();
	void dibuja();
	void copia_nivel1();
	void textura(int fil, int col, float altura, char const* cadena1);
	void cargarBordes(ListaParedes& bordes);

	friend class Interaccion;
};