#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
	radio = 0.25;
}

void Disparo::setPos(float ix, float iy) {
	posicion.x = origen.x = ix;
	posicion.y = origen.y = iy;
	temporizador = 30;
	rebote = true;
}

Vector2D Disparo::getPos() {
	return posicion;
}

void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

float Disparo::getRadio() {
	return radio;
}

void Disparo::dibuja() {
	if (temporizador >= 0) {//PENDIENTE DE CAMBIO
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
	//CUANDO SE ACABE EL TIEMPO SE DEBERÍA ACTIVAR EL DESTRUCTOR, PERO POR AHORA PARA HACER PRUEBAS NOS VALE
}

void Disparo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	origen = posicion - velocidad * 5*t;
	velocidad = velocidad + aceleracion * t;
	temporizador -= t;
}