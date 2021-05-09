#include "Jugador.h"
#include "freeglut.h"

Jugador::Jugador() {
	posicion.x = 0;
	posicion.y = 0;
	orientacion = 90;
	velangular = 0;
	radio = 0.1f;
	color.r = 255;
	color.g = 0;
	color.b = 0;
}

void Jugador::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	orientacion += velangular * t;
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

void Jugador::setVel(float ivx, float ivy) {
	velocidad.x = ivx;
	velocidad.y = ivy;
}

Vector2D Jugador::getVel() {
	return velocidad;
}

void Jugador::setOri(float o) {
	orientacion = o;
}

float Jugador::getOri() {
	return orientacion;
}

void Jugador::setVelAng(float iv) {
	velangular = iv;
}

float Jugador::getVelAng() {
	return velangular;
}

void Jugador::teclaAbajo(unsigned char key) {
	switch (key)
	{
	case 'w':
		setVel(getVel().x, getVel().y + 2);
		break;
	case 'a':
		setVel(getVel().x - 2, getVel().y);
		break;
	case 's':
		setVel(getVel().x, getVel().y - 2);
		break;
	case 'd':
		setVel(getVel().x + 2, getVel().y);
		break;
	}
}

void Jugador::teclaArriba(unsigned char key) {
	switch (key)
	{
	case 'w':
		setVel(getVel().x, getVel().y - 2);
		break;
	case 'a':
		setVel(getVel().x + 2, getVel().y);
		break;
	case 's':
		setVel(getVel().x, getVel().y + 2);
		break;
	case 'd':
		setVel(getVel().x - 2, getVel().y);
		break;
	}
}

void Jugador::teclaEspecialAbajo(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_UP:

		break;
	case GLUT_KEY_DOWN:

		break;
	case GLUT_KEY_LEFT:
		setVelAng(getVelAng() + 100);
		break;
	case GLUT_KEY_RIGHT:
		setVelAng(getVelAng() - 100);
		break;
	}
}

void Jugador::teclaEspecialArriba(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_UP:

		break;
	case GLUT_KEY_DOWN:

		break;
	case GLUT_KEY_LEFT:
		setVelAng(getVelAng() - 100);
		break;
	case GLUT_KEY_RIGHT:
		setVelAng(getVelAng() + 100);
		break;
	}
}