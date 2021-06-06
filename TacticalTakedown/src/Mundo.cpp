#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

#define PI 3.141592

void Mundo::dibuja() {
	camara.dibuja();
	//mapa.dibuja(jugador,enemigo); //falta disparos //falta pasarlo a lista de enemigos
	//mapa.cargarBordes(bordes);

	glEnable(GL_LIGHTING);	//Activa la iluminación previo al dibujo de objetos

	jugador.dibuja();
	enemigo.dibuja();

	disparos.dibuja();

	for (int i = 0; i < 4; i++) {
		pared[i].dibuja();
	}

	
	glDisable(GL_LIGHTING); //Desactiva la iluminación, para que todas las figuras reaccionen igual con la iluminación
}

void Mundo::mueve() 
{
	jugador.mueve(0.020f);

	for (int i = 0; i < 4; i++) {
		Interaccion::colision(jugador, pared[i]);
		Interaccion::colision(enemigo, pared[i]);
	}

	//bordes.colision(jugador);
	//mapa.cargarBordes(jugador);

	enemigo.persiguePunto(jugador.getPos());

	float aux = 0; //Pendiente de un apaño
	for (int i = 0; i < 4; i++) {
		if (pared[i].obstaculiza(enemigo.getPos(), jugador.getPos()))
			aux = 1;
	}
	if (aux == 0)
		enemigo.mueve(0.020f);

	disparos.mueve(0.020f);

	for (int i = 0; i < 4; i++) {
		Disparo* aux = disparos.colision(pared[i]); //Devuelve la dirección de aquell disparo que ha colisionado con la pared
		if (aux != 0 && (aux->getRebote() <= 0))	//si algún disparo ha colisionado y a este no le quedan rebotes
			disparos.eliminar(aux);
	}
	
	camara.setPos(jugador.getPos().x, jugador.getPos().y);
}

void Mundo::inicializa()
{
	jugador.setPos(0, 0);
	enemigo.setPos(1, 1);

	pared[0].setPos(0, -10, 10, -10);
	pared[1].setPos(10, -10, 10, 10);
	pared[2].setPos(10, 10, -10, 10);
	pared[3].setPos(-10, 10, -10, 0);
}

void Mundo::teclaAbajo(unsigned char key) 
{
	jugador.teclaAbajo(key);

	switch (key) {
	case (' '):
		Disparo* d = new Disparo();
		d->setPos(jugador.getPos().x, jugador.getPos().y);
		d->setVel(20 * cos(jugador.getOri() * (PI / 180)), 20 * sin(jugador.getOri() * (PI / 180)));
		disparos.agregar(d);
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
	//esferas.destruirContenido();
	disparos.destruirContenido();
	enemigos.destruirContenido();
	mapa.destruirContenido();
}

void Mundo::musica() {//funcion musica, es necesaria pararlo
	//ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}