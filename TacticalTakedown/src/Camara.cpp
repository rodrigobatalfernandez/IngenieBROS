#include "Camara.h"
#include "freeglut.h"

Camara::Camara() {
	posicion.x = 0;
	posicion.y = 0;
	mira.x = 0;
	mira.y = 0;
}

void Camara::dibuja() {
	gluLookAt(posicion.x, posicion.y,  50,
			      mira.x,     mira.y,   0,
					   0,		   1,   0);
}

void Camara::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
	mira.x = ix;
	mira.y = iy;
}