#pragma once
#include "Vector2D.h"

class Disparo {
	friend class Interaccion;
private:
	float radio;
	float temporizador;
	Vector2D posicion, velocidad, aceleracion;
	Vector2D origen;
	bool rebote; //Solo se permite un rebote
public:
	Disparo();
	//virtual ~Disparo();
	void setPos(float ix, float iy);
	Vector2D getPos();
	void setVel(float vx, float vy);
	float getRadio();
	void dibuja();
	void mueve(float t);
};