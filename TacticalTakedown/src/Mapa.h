#pragma once
#include "Pared.h"

class Mapa {
private:
	Pared techo, suelo, pared_dcha, pared_izda;
public:
	Mapa();
	//virtual ~Mapa();
	void dibuja();

	friend class Interaccion;
};