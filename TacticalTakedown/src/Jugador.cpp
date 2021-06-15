#include "Jugador.h"
#include "freeglut.h"
#include "ETSIDI.h"

#define ESCALA 3
#define PI 3.141592f


Jugador::Jugador() {
	posicion.x = 0;
	posicion.y = 0;
	orientacion = 90;
	velangular = 0;
	vel_avance = 15;
	vel_rotacion = 225;
	radio = 1.5f;
	indice = 7 + 8 * color;
	cooldown = 0;
}

void Jugador::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	orientacion += velangular * t;
	cooldown--;
}

void Jugador::dispara(ListaDisparos& disparos)
{
	if ( cooldown <= 0) {
		Disparo* d = new Disparo();
		d->setPos(posicion.x, posicion.y);
		d->setVel(20 * cos(orientacion * (PI / 180)), 20 * sin(orientacion * (PI / 180)));
		disparos.agregar(d);
		cooldown = COOLDOWN_DISP;
	}
}

void Jugador::dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(orientacion, 0, 0, 1);
	if (velocidad.modulo() > 0) {
		if ((indice > 8*color) && (indice <= 7+8*color))
			indice--;
		else
			indice = 7+8*color;
	}
	ETSIDI::SpriteSequence animacion("imagenes/TANKHUNG.png", 8, 8, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, indice);
	animacion.draw();
	glRotatef(-orientacion, 0, 0, 1);
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

void Jugador::Cooldown(bool baja)
{
	COOLDOWN_DISP = 30 - baja * 15;
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
	case 'w': {
		setVel(getVel().x, getVel().y + vel_avance);
		break; }

	case 'a': {
		setVel(getVel().x - vel_avance, getVel().y);
		break; }

	case 's': {
		setVel(getVel().x, getVel().y - vel_avance);
		break; }
	case 'd': {
		setVel(getVel().x + vel_avance, getVel().y);
		break; }

	}
}

void Jugador::teclaArriba(unsigned char key) {
	switch (key)
	{

	case 'w': {
		setVel(getVel().x, getVel().y - vel_avance);
		break; }

	case 'a': {
		setVel(getVel().x + vel_avance, getVel().y);
		break; }

	case 's': {
		setVel(getVel().x, getVel().y + vel_avance);
		break; }

	case 'd': {
		setVel(getVel().x - vel_avance, getVel().y);
		break; }
	}
}

void Jugador::teclaEspecialAbajo(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		setVelAng(getVelAng() + vel_rotacion);
		break;
	case GLUT_KEY_RIGHT:
		setVelAng(getVelAng() - vel_rotacion);
		break;
	}
}

void Jugador::teclaEspecialArriba(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		setVelAng(getVelAng() - vel_rotacion);
		break;
	case GLUT_KEY_RIGHT:
		setVelAng(getVelAng() + vel_rotacion);
		break;
	}
}