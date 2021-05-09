#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Enemigo
{
private:
	Vector2D posicion, velocidad, aceleracion;
	float orientacion, velangular;
	float vel_avance, vel_respuesta;

	ColorRGB color;
	float radio; //Definición del radio de la hitbox
public:
	Enemigo(float xi = 0, float yi = 0, float ori = 0);
	void dibuja();
	void mueve(float t);

	void setPos(float ix, float iy);
	Vector2D getPos();
	void setVel(float ivx, float ivy);
	Vector2D getVel();
	void setOri(float o);
	float getOri();
	void setVelAng(float vo);
	float getVelAng();

	void miraPunto(Vector2D Objetivo);
	void persiguePunto(Vector2D Objetivo);
};