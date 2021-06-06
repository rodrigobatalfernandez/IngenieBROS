#include "Torreta.h"

void Torreta::mueve(float t)
{
	//No se mueve
	orientacion += velangular * t;
}

void Torreta::dibuja()
{
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(orientacion, 0, 1, 0);
	glutSolidTeapot(radio);
	//Falta imagen chula
	glRotatef(-orientacion, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Torreta::persiguePunto(Vector2D Objetivo)
{
	miraPunto(Objetivo);
}
