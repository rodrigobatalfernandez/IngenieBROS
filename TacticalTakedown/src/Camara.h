#pragma once
#include "Vector2D.h"

class Camara
{
private:
	Vector2D posicion, velocidad;
	Vector2D mira;
public:
	Camara();
	void dibuja();
};