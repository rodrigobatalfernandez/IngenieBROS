#include "Torreta.h"

#define ESCALA 6

void Torreta::setPos(float ix, float iy)
{
	pos_fija.x = posicion.x = ix;
	pos_fija.y = posicion.y = iy;

}

Torreta::Torreta()
{
	COOLDOWN_DISP = 20;
	vel_rotacion = 4;
}

void Torreta::mueve(float t)
{
	//No se mueve
	posicion = pos_fija;
	orientacion += velangular * t;
	if (orientacion > 360)
		orientacion -= 360;
	else if (orientacion < 0)
		orientacion += 360;
}

void Torreta::dibuja()
{
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(orientacion + 180, 0, 0, 1);

	ETSIDI::SpriteSequence animacion("imagenes/TORRETASINPATAS1.png", 1, 1, 50, true, 0, 0, 1 * ESCALA, 0.566265 * ESCALA, 0);
	animacion.draw();

	glRotatef(-orientacion - 180, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

