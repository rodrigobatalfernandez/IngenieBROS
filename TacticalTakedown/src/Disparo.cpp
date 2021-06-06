#include "Disparo.h"
#include "freeglut.h"
#include "ETSIDI.h"
#define ESCALA 1

Disparo::Disparo() {
	radio = 0.25f;
	textura = false;
	indice = 0;
	rebote = 0;
	orientacion = 0;

}

void Disparo::setPos(float ix, float iy) {
	posicion.x = origen.x = ix;
	posicion.y = origen.y = iy;
	rebote = 2;
}

void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Disparo::dibuja() {
		getOri();
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0);
		glRotatef(90, 0, 0, 1);
		glRotatef(-orientacion, 0, 0, 1);
		//glutSolidSphere(radio, 20, 20);
		if ((indice >= 0) && (indice < 11))
			indice++;
		else
			indice = 0;
		if (textura) {
			ETSIDI::SpriteSequence animacion("imagenes/laser.png", 1, 11, 50, true, 0, 0, 2 * ESCALA, 1 * ESCALA, indice);
			animacion.draw();
		}
		else {
			ETSIDI::SpriteSequence animacion("imagenes/laser4.png", 1, 11, 50, true, 0, 0, 2 * ESCALA, 1 * ESCALA, indice);
			animacion.draw();
		}
		glRotatef(orientacion, 0, 0, 1);
		glRotatef(-90, 0, 0, 1);
		glTranslatef(-posicion.x, -posicion.y, 0);
		glPopMatrix();
		glEnd();
}

void Disparo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	origen = posicion - velocidad * 5*t;
	velocidad = velocidad + aceleracion * t;
}
void Disparo::getOri() {
	orientacion = 180 / 3.141592 * atan2(velocidad.x, velocidad.y);
}
void Disparo::sonido_disparo_inicio() {
	ETSIDI::play("sonidos/DISPARO.wav");
}
void Disparo::sonido_disparo_impacto() {
	ETSIDI::play("sonidos/IMPACTO LASER.wav");
}