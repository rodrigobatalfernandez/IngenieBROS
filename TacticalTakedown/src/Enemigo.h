#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Enemigo
{
	friend class Interaccion;
protected:
	//Cinematica
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	float orientacion; //Define un angulo (sexagesimal) sobre el que gira, +
	float velangular; //Velocidad de rotacion
	float vel_avance; //Parametro que define el modulo de la velocidad a la que avanza
	float vel_rotacion; //Parametro que define a la velocidad a la que va a variar la velocidad angular

	ColorRGB color; //Definicion del color
	float radio; //Definición del radio de la hitbox
public:
	Enemigo(float xi = 0, float yi = 0, float ori = 0); //Constructor
	virtual void dibuja(); //Funcion de dibujo
	virtual void mueve(float t); //Cinematica

	void setPos(float ix, float iy);  //Define una nueva posicion
	Vector2D getPos();  //Devuelve la posicion
	void setVel(float ivx, float ivy); //Define una nueva velocidad
	Vector2D getVel(); //Devuelve la velocidad
	void setOri(float o); //Define una nueva orientacion
	float getOri(); //Devuelve la orientacion actual
	void setVelAng(float vo); //Define una nueva velocidad angular
	float getVelAng(); //Devuelve la velocidad angular actual

	virtual void miraPunto(Vector2D Objetivo); //Recive un punto y lo mira
	virtual void persiguePunto(Vector2D Objetivo); //Recive un punto y lo sigue
};