#pragma once
#include "Vector2D.h"

class Bonus{
public:
	Bonus();
	//virtual ~Bonus();
	float lado;
	Vector2D posicion, velocidad, aceleracion;
public:
	void dibuja();
	void mueve(float t);
};