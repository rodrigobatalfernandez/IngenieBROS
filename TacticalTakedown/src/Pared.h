#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"

class Pared {

private:
	ColorRGB color;
	Vector2D limite1, limite2;
public:
	Pared();
	//virtual ~Pared();
	void setPos(float x1, float y1, float x2, float y2);
	void setColor(Byte r, Byte v, Byte a);
	void dibuja();

	float distancia(Vector2D punto, Vector2D* direccion = 0);
	bool obstaculiza(Vector2D p1, Vector2D p2);		//Para saber si dos puntos están en linea de visión u obstaculizados con pared

	friend class Interaccion;
};