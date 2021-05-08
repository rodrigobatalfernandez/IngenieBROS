#include "Camara.h"
#include "freeglut.h"

Camara::Camara() {
	posicion.x = 0;
	posicion.y = 0;
	mira.x = 0;
	mira.y = 0;
}

void Camara::dibuja() {
	gluLookAt(posicion.x, posicion.y,  -1,
			      mira.x,     mira.y,   0,
					   0,		   1,   0);
}