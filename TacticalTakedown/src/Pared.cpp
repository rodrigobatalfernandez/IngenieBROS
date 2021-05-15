#include "Pared.h"
#include "freeglut.h"
#include <iostream>

Pared::Pared() {
	color.set(255, 255, 255);
}

void Pared::setPos(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

void Pared::setColor(Byte r, Byte v, Byte a) {
	color.set(r, v, a);
}

void Pared::dibuja()
{
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_LINES);
	glVertex2d(limite1.x, limite1.y);
	glVertex2d(limite2.x, limite2.y);
	glEnd();
}

//Calculo de distancia de una pared a un punto, adicionalmente 
//se modifica el valor de un vector direccion opcional que contendr� 
//el vector unitario saliente que indica la direccion de la 
//recta m�s corta entre el punto y la pared.
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);						//Vector del extremo del segmento al punto
	Vector2D v = (limite2 - limite1).unitario();		//Vector unitario al segmento
	float longitud = (limite1 - limite2).modulo();		//Longitud del segmento
	Vector2D dir;
	float valor = u * v;								//Proyecci�n de "u" sobre el segmento
	float distancia = 0;
	if (valor < 0)										//Proyecci�n cae fuera del segmento por el lado de "lim1"
		dir = u;											//El vector que une es desde "lim1" al punto
	else if (valor > longitud)							//Proyecci�n se sale fuera del segmento por el lado de "lim2"
		dir = (punto - limite2);							//El vector que une es desde "lim2" al punto
	else												//Proyecci�n cae dentro del segmento
		dir = u - v * valor;								//El vector que le une es el normal al segmento pasando por el punto
	distancia = dir.modulo();							//Distancia que los separa es la longitud de este vector
	if (direccion != 0)
		*direccion = dir.unitario();					//De haber cargado una direcci�n, se almacena en ella el unitario normal al segmento
	return distancia;
}

bool Pared::obstaculiza(Vector2D p1, Vector2D p2) {
	Vector2D a, b, c;
	a = limite2 - limite1;
	b = p2 - p1;
	c = p1 - limite1;

	float s = (c.x - (c.y * (b.x / b.y))) / (a.x - (a.y * (b.x / b.y)));
	float t = (c.x - (c.y * (a.x / a.y))) / (-b.x + (b.y * (a.x / a.y)));

	if ((s >= 0) && (s <= 1) && (t >= 0) && (t <= 1)) {
		std::cout << "para" << std::endl;
		return true;
	}
	std::cout << "sigue" << std::endl;
	return false;
}//https://es.wikipedia.org/wiki/Intersecci%C3%B3n_(geometr%C3%ADa)#:~:text=En%20geometr%C3%ADa%2C%20una%20intersecci%C3%B3n%20es,planos%2C%20superficies%20o%20vol%C3%BAmenes).