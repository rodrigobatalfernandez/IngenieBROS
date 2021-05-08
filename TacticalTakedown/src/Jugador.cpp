#include "Jugador.h"
#include "freeglut.h"

Jugador::Jugador() {
	posicion.x = 0;
	posicion.y = 0;
	orientacion = 0;
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
	glRotatef(orientacion, 0, 1, 0);
	glutSolidTeapot(radio);
	glTranslatef(-posicion.x, -posicion.y, 0);
}