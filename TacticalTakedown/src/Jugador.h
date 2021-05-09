#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Jugador{
private:
	Vector2D posicion, velocidad, aceleracion;
	float orientacion, velangular;
	ColorRGB color;
	float radio; //Definición del radio de la hitbox
public:
	Jugador();
	void dibuja();
	void mueve(float t);

	void setPos(float ix, float iy);
	Vector2D getPos();
	void setVel(float ivx, float ivy);
	Vector2D getVel();

	void setOri(float iv);
	float getOri();
	void setVelAng(float iv);
	float getVelAng();

	void teclaAbajo(unsigned char key);
	void teclaArriba(unsigned char key);
	void teclaEspecialAbajo(unsigned char key);
	void teclaEspecialArriba(unsigned char key);
};