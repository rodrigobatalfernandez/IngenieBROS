#pragma once
#include "Vector2D.h"

class Disparo {
	friend class Interaccion;
private:
	float radio;
	Vector2D posicion, velocidad, aceleracion;
	//Vector2D origen;
	int rebote; //Solo se permite un rebote
	int indice;
	float orientacion;

public:
	Disparo();
	//virtual ~Disparo();
	void setPos(float ix, float iy);
	Vector2D getPos() { return posicion; }
	void setVel(float vx, float vy);
	float getRadio() { return radio; }
	int getRebote() { return rebote; }
	void dibuja(bool textura = false);
	void mueve(float t);
	void getOri();
	//void Tex() { textura = true; } //Cambia la textura del disparo a la del aliado
	void sonido_disparo_inicio();
	void sonido_disparo_impacto();
};