#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo() {
	float dist = sqrt((double)x_ojo * (double)x_ojo + (double)z_ojo * (double)z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::dibuja() {
	camara.dibuja();

	glEnable(GL_LIGHTING);	//Desactiva la iluminación previo al dibujo de objetos

	jugador.dibuja();

	/*esferas.dibuja();
	disparos.dibuja();
	caja.dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	bonus.dibuja();*/

	glDisable(GL_LIGHTING); //Reactiva la iluminación, para que todas las figuras reaccionen igual con la iluminación
}

void Mundo::mueve() {
	/*hombre.mueve(0.025f);
	esferas.mueve(0.025f);
	bonus.mueve(0.025f);
	disparos.mueve(0.025f);

	Interaccion::rebote(hombre, caja);

	esferas.rebote();
	esferas.rebote(plataforma);
	esferas.rebote(caja);
	Esfera* aux = esferas.colision(hombre); //Devuelve la dirección de aquella esfera que haya chocado con el hombre
	if (aux != 0)//si alguna esfera ha chocado
		esferas.eliminar(aux);

	disparos.colision(plataforma);
	disparos.colision(caja);*/
}

void Mundo::inicializa() {
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	/*bonus.setPos(5.0f, 5.0f);

	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);

	Esfera* e1 = new Esfera(1, 2, 4, 5, 15); // esfera1
	e1->setColor(200, 0, 0);
	esferas.agregar(e1); // esfera1 a la lista
	Esfera* e2 = new Esfera(2, -2, 4, -5, 15); // esfera2
	e2->setColor(255, 255, 255);
	esferas.agregar(e2); //esfera2 a la lista
	for (int i = 0; i < 6; i++)
	{
		Esfera* aux = new Esfera(0.75 + i * 0.25, i, 1 + i, i, i);
		esferas.agregar(aux);
	}*/
}

void Mundo::tecla(unsigned char key) {
	/*switch (key)
	{
	case '1':
		esferas.agregar(new Esfera(0.5f, 0, 10));
		break;
	case '2':
		esferas.agregar(new Esfera(1.0f, 0, 10));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5f, 0, 10));
		break;
	case '4':
		esferas.agregar(new Esfera(2.0f, 0, 10));
		break;
	case ' ':
		Disparo * d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y);
		disparos.agregar(d);
		break;
	}*/
}

void Mundo::teclaEspecial(unsigned char key) {
	/*switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	}*/
}

Mundo::~Mundo()
{
	/*esferas.destruirContenido();
	disparos.destruirContenido();*/
}