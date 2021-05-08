#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

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

	jugador.mueve(0.025f);
	
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

void Mundo::tecla(unsigned char key) 
{
	switch (key)
	{
	case 'w':
		jugador.setPos(jugador.getPos().x, jugador.getPos().y + 0.1);
		break;
	case 'a':
		jugador.setPos(jugador.getPos().x - 0.1, jugador.getPos().y);
		break;
	case 's':
		jugador.setPos(jugador.getPos().x, jugador.getPos().y - 0.1);
		break;
	case 'd':
		jugador.setPos(jugador.getPos().x + 0.1, jugador.getPos().y);
		break;
	case ' ':
		/*Disparo * d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y);
		disparos.agregar(d);*/
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_UP:
		jugador.setOri(90);
		break;
	case GLUT_KEY_DOWN:
		jugador.setOri(270);
		break;
	case GLUT_KEY_LEFT:
		jugador.setOri(180);
		break;
	case GLUT_KEY_RIGHT:
		jugador.setOri(0);
		break;
	}
}

Mundo::~Mundo()
{
	/*esferas.destruirContenido();
	disparos.destruirContenido();*/
}
void Mundo::musica() {//funcion musica, es necesaria pararlo
	ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}