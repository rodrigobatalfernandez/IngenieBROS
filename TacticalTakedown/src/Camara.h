#pragma once
#include "Vector2D.h"

class Camara
{
private:
	Vector2D posicion, velocidad;
	Vector2D mira;
public:
	Camara();
	void setPos(float ix, float iy);
	void dibuja();
	Vector2D getPos() { return posicion; }
};