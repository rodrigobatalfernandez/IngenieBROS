#include "Lapa.h"

#define ESCALA 6

Lapa::Lapa()
{
	vel_avance = 16;
}

void Lapa::dibuja()
{
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(orientacion + 180, 0, 0, 1);

	//Falta imagen chula
	ETSIDI::SpriteSequence animacion("imagenes/SovietChiquito.png", 1, 1, 50, true, 0, 0, 1 * ESCALA, 0.566265 * ESCALA, 0);
	animacion.draw();

	//glRotatef(-90, 1, 0, 0);
	glRotatef(-orientacion - 180, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
