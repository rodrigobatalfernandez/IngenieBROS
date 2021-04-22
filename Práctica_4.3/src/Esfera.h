#pragma once
#include "Vector2D.h"

class Esfera{
private:
	float radio;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
public:
	Esfera();
	//virtual ~Esfera();
	void setRadius(float r);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x, float y);
	void dibuja();
	void mueve(float t);
};