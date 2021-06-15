#pragma once
#include "Vector2D.h"

class Camara{
private:
	Vector2D posicion;
	//Vector2D mira;

public:
	Camara();

	void setPos(float ix, float iy);
	Vector2D getPos() { return posicion; }

	void dibuja();
};