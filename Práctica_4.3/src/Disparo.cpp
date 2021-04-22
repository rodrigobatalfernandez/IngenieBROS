#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
	radio = 0.25f;
	velocidad.y = 20;
}

void Disparo::dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex2d(origen.x, origen.y);
	glVertex2d(posicion.x, posicion.y);
	glEnd();
}

void Disparo::mueve(float t) {
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}