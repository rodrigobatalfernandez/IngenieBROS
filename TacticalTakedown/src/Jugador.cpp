#include "Jugador.h"
#include "freeglut.h"

#define PI 3.141592

Jugador::Jugador() {
	posicion.x = 0;
	posicion.y = 0;
	orientacion = 90;
	radio = 0.1f;
	color.r = 255;
	color.g = 0;
	color.b = 0;
}

void Jugador::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::dibuja() {
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);

	glRotatef(90, 1, 0, 0);
	glRotatef(orientacion, 0, 1, 0);
	glutSolidTeapot(radio);
	glRotatef(-orientacion, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Jugador::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

Vector2D Jugador::getPos() {
	return posicion;
}

void Jugador::setOri(float o) {
	orientacion = o;
}

void Jugador::setVel(float ivx, float ivy) {
	velocidad.x = ivx;
	velocidad.y = ivy;
}

float Jugador::getOri() {
	return orientacion;
}