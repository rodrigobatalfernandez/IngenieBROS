#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Jugador{
private:
	Vector2D posicion, velocidad, aceleracion;
	float orientacion;
	ColorRGB color;
	float radio; //Definición del radio de la hitbox
public:
	Jugador();
	void dibuja();
	void mueve(float t);
};