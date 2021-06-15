#pragma once
#include "Vector2D.h"

class Pared {

private:
	Vector2D limite1, limite2;
public:
	Pared();
	void setPos(float x1, float y1, float x2, float y2);
	void dibuja();

	float distancia(Vector2D punto, Vector2D* direccion = 0);
	bool obstaculiza(Vector2D p1, Vector2D p2);		//Para saber si dos puntos están en linea de visión u obstaculizados con pared

	friend class Interaccion;
};