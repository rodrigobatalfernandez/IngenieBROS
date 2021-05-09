#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#define PI 3.141592

void Mundo::dibuja() {
	camara.dibuja();
	mapa.dibuja();

	glEnable(GL_LIGHTING);	//Activa la iluminación previo al dibujo de objetos

	jugador.dibuja();
	enemigo.dibuja();
	disparo.dibuja();
	for (int i = 0; i < 4; i++) {
		pared[i].dibuja();
	}

	/*esferas.dibuja();
	disparos.dibuja();
	caja.dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	bonus.dibuja();*/

	glDisable(GL_LIGHTING); //Desactiva la iluminación, para que todas las figuras reaccionen igual con la iluminación
}

void Mundo::mueve() {

	for (int i = 0; i < 4; i++) {
		Interaccion::colision(jugador, pared[i]);
		Interaccion::colision(enemigo, pared[i]);
		Interaccion::colision(disparo, pared[i]);
	}

	jugador.mueve(0.020f);

	enemigo.persiguePunto(jugador.getPos());
	//enemigo.miraPunto(jugador.getPos());
	enemigo.mueve(0.020f);

	disparo.mueve(0.020f);
	
	camara.setPos(jugador.getPos().x, jugador.getPos().y);
}

void Mundo::inicializa()
{
	jugador.setPos(0, 0);
	enemigo.setPos(1, 1);
	disparo.setPos(0, 0);
	pared[0].setPos(-10, -10, 10, -10);
	pared[1].setPos(10, -10, 10, 10);
	pared[2].setPos(10, 10, -10, 10);
	pared[3].setPos(-10, 10, -10, -10);

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

void Mundo::teclaAbajo(unsigned char key) 
{
	jugador.teclaAbajo(key);

	switch (key) {
	case (' '):
		disparo.setPos(jugador.getPos().x, jugador.getPos().y);
		disparo.setVel(20 * cos(jugador.getOri()*(PI/180)), 20 * sin(jugador.getOri()*(PI / 180)));
		break;
	}
}

void Mundo::teclaArriba(unsigned char key)
{
	jugador.teclaArriba(key);

}

void Mundo::teclaEspecialAbajo(unsigned char key) 
{
	jugador.teclaEspecialAbajo(key);

}

void Mundo::teclaEspecialArriba(unsigned char key) {
	jugador.teclaEspecialArriba(key);

}

Mundo::~Mundo()
{
	/*esferas.destruirContenido();
	disparos.destruirContenido();*/
}

void Mundo::musica() {//funcion musica, es necesaria pararlo
	//ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}