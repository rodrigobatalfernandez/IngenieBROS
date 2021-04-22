#pragma once
#include "Vector2D.h"

class Hombre{
public:
	Hombre();
	//virtual ~Hombre();
	float altura;
	Vector2D posicion, velocidad, aceleracion;
public:
	void dibuja();
	void mueve(float t);
};