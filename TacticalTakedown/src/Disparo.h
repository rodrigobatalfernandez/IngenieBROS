#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Disparo {
	friend class Interaccion;
private:
	float radio;
	Vector2D posicion, velocidad, aceleracion;
	Vector2D origen;
	int rebote; //Solo se permite un rebote
	int indice;
	float orientacion;

public:
	Disparo();
	//virtual ~Disparo();
	void setPos(float ix, float iy);
	Vector2D getPos();
	void setVel(float vx, float vy);
	float getRadio();
	int getRebote();
	void dibuja();
	void mueve(float t);
	void getOri();
};