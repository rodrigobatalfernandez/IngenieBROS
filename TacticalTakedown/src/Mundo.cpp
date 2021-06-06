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
	enemigos.dibuja();

	disparos.dibuja();
	disparos_enemigos.dibuja();

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
		//Interaccion::colision(enemigo, pared[i]);
	}

	//bordes.colision(jugador);
	//mapa.cargarBordes(jugador);

	enemigos.persiguePunto(jugador.getPos());

	//float aux = 0; //Pendiente de un apaño
	//for (int i = 0; i < 4; i++) {
	//	if (pared[i].obstaculiza(enemigo.getPos(), jugador.getPos()))
	//		aux = 1;
	//}
	//if (aux == 0)
		enemigos.mueve(0.020f);

	enemigos.dispara(jugador.getPos(), disparos_enemigos);

	disparos.mueve(0.020f);
	disparos_enemigos.mueve(0.020f);

	for (int i = 0; i < 4; i++) {
		Disparo* aux = disparos.colision(pared[i]); //Devuelve la dirección de aquell disparo que ha colisionado con la pared
		if (aux != 0 && (aux->getRebote() <= 0))	//si algún disparo ha colisionado y a este no le quedan rebotes
			disparos.eliminar(aux);
	}

	Interaccion::colision(enemigos, disparos);
	
	camara.setPos(jugador.getPos().x, jugador.getPos().y);
}

void Mundo::inicializa()
{
	nivel = 0;//No se si va aqui

	cargarNivel();
}

void Mundo::teclaAbajo(unsigned char key) 
{
	jugador.teclaAbajo(key);

	switch (key) {
	case (' '):
		Disparo* d = new Disparo();
		d->Tex();
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
	disparos.destruirContenido();
	enemigos.destruirContenido();
	mapa.destruirContenido();
}

bool Mundo::cargarNivel()
{
	muerte = false;// temporal
	nivel++;
	jugador.setPos(0, 0);//Posicion inicial, comun para todos los niveles

	//Destruir cosas
	enemigos.destruirContenido();
	disparos.destruirContenido();

	if (nivel == 1)
	{
		//Nivel 1
		
		for (int i = 0; i < 4; i++) {
			Enemigo* e = new Enemigo();
			e->setPos(2*i,2*i);
			enemigos.agregar(e);
		}

		pared[0].setPos(0, -10, 10, -10);
		pared[1].setPos(10, -10, 10, 10);
		pared[2].setPos(10, 10, -10, 10);
		pared[3].setPos(-10, 10, -10, 0);
	}
	if (nivel == 2)
	{
		//Nivel 2
	}
	if (nivel == 3)
	{
		//Nivel 3
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::musica() {//funcion musica, es necesaria pararlo
	//ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}