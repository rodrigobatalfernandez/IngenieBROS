#pragma once
#include "Vector2D.h"

class Pared{
private:
	unsigned char rojo, verde, azul;
public:
	Vector2D limite1, limite2;
public:
	Pared();
	//virtual ~Pared();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void dibuja();
};