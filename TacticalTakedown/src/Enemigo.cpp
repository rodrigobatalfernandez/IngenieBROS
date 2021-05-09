#include "Enemigo.h"
#define PI 3.141592

Enemigo::Enemigo(float xi, float yi, float ori)
{
	posicion.x = xi;
	posicion.y = yi;
	orientacion = ori;
	velangular = 0;
	radio = 1.0f;
	color.r = 0;
	color.g = 255;
	color.b = 0;
}

void Enemigo::dibuja()
{
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);

	glRotatef(90, 1, 0, 0);
	glRotatef(orientacion, 0, 1, 0);
	glutSolidTeapot(radio);
	glRotatef(-orientacion, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Enemigo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	orientacion += velangular * t;
}

void Enemigo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

Vector2D Enemigo::getPos()
{
	return posicion;
}

void Enemigo::setVel(float ivx, float ivy)
{
	velocidad.x = ivx;
	velocidad.y = ivy;
}

Vector2D Enemigo::getVel()
{
	return velocidad;
}

void Enemigo::setOri(float o)
{
	orientacion = o;
}

float Enemigo::getOri()
{
	return orientacion;
}

void Enemigo::setVelAng(float vo)
{
	velangular = vo;
}

float Enemigo::getVelAng()
{
	return velangular;
}

void Enemigo::miraPunto(Vector2D Objetivo)
{
	orientacion = 180 / PI * (posicion - Objetivo).argumento() + 180;
}