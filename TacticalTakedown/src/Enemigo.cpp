#include "Enemigo.h"
#include <math.h>

#define PI 3.141592
#define COOLDOWN_DISP 60
#define COOLDOWN_MOV 40
#define ESCALA 3


Enemigo::Enemigo(float xi, float yi, float ori)
{
	posicion.x = xi;
	posicion.y = yi;
	orientacion = ori;
	velangular = 0;
	vel_rotacion = 2;
	vel_avance = 8;
	radio = 1.5f;
	indice = 0;
	cooldown_disparo = 0;
	cooldown_movimiento = 0;
}

void Enemigo::dibuja()
{
	//glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(orientacion, 0, 0, 1);

	if ((indice > 8) && (indice <= 15))
		indice--;
	else
		indice = 15;
	ETSIDI::SpriteSequence animacion("imagenes/TANKHUNG.png", 8, 8, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, indice);
	animacion.draw();

	glRotatef(-orientacion, 0, 0, 1);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Enemigo::mueve(float t)
{
	posicion = posicion + velocidad * t;// + aceleracion * (0.5f * t * t);
	//velocidad = velocidad; //+ aceleracion * t;

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

void Enemigo::redCoolMov() {
	cooldown_movimiento--;
}

void Enemigo::resCoolMov() {
	cooldown_movimiento = COOLDOWN_MOV;
}

float Enemigo::getCoolMov() {
	return cooldown_movimiento;
}

float Enemigo::difAngular(Vector2D& Objetivo) {
	//float ori_deseada = 180 / PI * (Objetivo - posicion).argumento();
	float dif_ori = (180 / PI * (Objetivo - posicion).argumento()) - orientacion;

	dif_ori = dif_ori > 180 ? (dif_ori - 360) : dif_ori; //por si se pasa el asunto de el márgen de +-180º
	dif_ori = dif_ori < -180 ? (dif_ori + 360) : dif_ori;

	/*if (dif_ori > 180) {//Ojito, que no se pase de vueltas el asunto
		dif_ori -= 360;
	}
	else if (dif_ori < -180) {
		dif_ori += 360;
	}*/

	return dif_ori;
}

void Enemigo::miraPunto(Vector2D& Objetivo)
{
	//float dif_ori = difAngular(Objetivo);

	velangular = vel_rotacion * difAngular(Objetivo);
}

void Enemigo::persiguePunto(Vector2D& Objetivo)
{
	//float dif_ori = difAngular(Objetivo);
	velangular = vel_rotacion * difAngular(Objetivo);

	setVel(vel_avance * cos(orientacion * (PI / 180)), vel_avance * sin(orientacion * (PI / 180)));
}

void Enemigo::dispara(Vector2D& Objetivo, ListaDisparos& disparos) {
	//float dif_ori = difAngular(Objetivo);

	cooldown_disparo--;
	if (abs(difAngular(Objetivo)) < 20 && cooldown_disparo <= 0) {
		Disparo* d = new Disparo();
		d->setPos(posicion.x, posicion.y);
		d->setVel(20 * cos(orientacion * (PI / 180)), 20 * sin(orientacion * (PI / 180)));
		disparos.agregar(d);
		cooldown_disparo = COOLDOWN_DISP;
	}
}