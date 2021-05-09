#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ETSIDI.h"
#define ESCALA 1

class Jugador{
	friend class Interaccion;
private:
	//Cinemática
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float orientacion; //Define un angulo (sexagesimal) sobre el que gira, (positivo antihorario)
	float vel_avance; //Parametro que define el modulo de la velocidad a la que avanza
	float vel_rotacion; //Parametro que define a la velocidad a la que va a variar la velociada angular
	float velangular; //Velocidad de rotacion
	int indice; //Indice de sprites

	ColorRGB color; //Definicion del color
	float radio; //Definición del radio de la hitbox
	int indice;	//Nº de sprite en la secuencia de animación
public:
	Jugador(); //Constructor
	void dibuja(); //Dibuja el personaje
	void mueve(float t); //Define la cinematica del personaje

	void setPos(float ix, float iy);  //Define una nueva posicion
	Vector2D getPos(); //Devuelve la posicion
	void setVel(float ivx, float ivy); //Define una nueva velocidad
	Vector2D getVel();  //Devuelve la velocidad

	void setOri(float iv); //Define una nueva orientacion
	float getOri(); //Devuelve la orientacion actual
	void setVelAng(float iv); //Define una nueva velocidad angular
	float getVelAng(); //Devuelve la velocidad angular actual

	void teclaAbajo(unsigned char key); //Interaccion cuando una tecla se pulsa
	void teclaArriba(unsigned char key); //Interaccion cuando una tecla se deja de pulsar
	void teclaEspecialAbajo(unsigned char key); //Interaccion cuando una tecla especial se pulsa
	void teclaEspecialArriba(unsigned char key); //Interaccion cuando una tecla especial se deja de pulsar
};