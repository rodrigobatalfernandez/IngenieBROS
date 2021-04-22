#pragma once
#include "Pared.h"

class Caja{
public:
	Caja();
	//virtual ~Caja();
	Pared techo, suelo, pared_dcha, pared_izda;
public:
	void dibuja();
};