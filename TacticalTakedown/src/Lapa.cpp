#include "Lapa.h"

#define ESCALA 3

Lapa::Lapa()
{
	vel_avance = 16;
}

void Lapa::dibuja()
{
	//glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(orientacion + 180, 0, 0, 1);

	if ((indice > 0) && (indice <= 8))
		indice--;
	else
		indice = 5;

	//Falta imagen chula
	ETSIDI::SpriteSequence animacion("imagenes/SpinnerRed.png", 4, 2, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, indice);
	animacion.draw();

	//glRotatef(-90, 1, 0, 0);
	glRotatef(-orientacion - 180, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
