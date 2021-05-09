#include "Pared.h"
#include "freeglut.h"

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
//se modifica el valor de un vector direccion opcional que contendrá 
//el vector unitario saliente que indica la direccion de la 
//recta más corta entre el punto y la pared.
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);						//Vector del extremo del segmento al punto
	Vector2D v = (limite2 - limite1).unitario();		//Vector unitario al segmento
	float longitud = (limite1 - limite2).modulo();		//Longitud del segmento
	Vector2D dir;
	float valor = u * v;								//Proyección de "u" sobre el segmento
	float distancia = 0;
	if (valor < 0)										//Proyección cae fuera del segmento por el lado de "lim1"
		dir = u;											//El vector que une es desde "lim1" al punto
	else if (valor > longitud)							//Proyección se sale fuera del segmento por el lado de "lim2"
		dir = (punto - limite2);							//El vector que une es desde "lim2" al punto
	else												//Proyección cae dentro del segmento
		dir = u - v * valor;								//El vector que le une es el normal al segmento pasando por el punto
	distancia = dir.modulo();							//Distancia que los separa es la longitud de este vector
	if (direccion != 0)
		*direccion = dir.unitario();					//De haber cargado una dirección, se almacena en ella el unitario normal al segmento
	return distancia;
}