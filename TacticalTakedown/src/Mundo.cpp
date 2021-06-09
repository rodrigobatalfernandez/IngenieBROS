#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

#define PI 3.141592

void Mundo::dibuja() 
{
	glEnable(GL_LIGHTING);	//Activa la iluminación previo al dibujo de objetos

	camara.dibuja();
	mapa.dibuja();
	//mapa.dibujaBordes();

	jugador.dibuja();
	enemigos.dibuja();

	disparos.dibuja();
	disparos_enemigos.dibuja();
	
	glDisable(GL_LIGHTING); //Desactiva la iluminación, para que todas las figuras reaccionen igual con la iluminación
}

void Mundo::mueve() 
{
	jugador.mueve(0.020f);

	enemigos.mueve(jugador.getPos(), mapa, 0.020f);
	enemigos.dispara(jugador.getPos(), disparos_enemigos, mapa);

	disparos.mueve(0.020f);
	disparos_enemigos.mueve(0.020f);

	Interaccion::colision(jugador, mapa);
	Interaccion::colision(enemigos, mapa);
	Interaccion::colision(disparos, mapa);
	Interaccion::colision(disparos_enemigos, mapa);
	Interaccion::colision(enemigos, disparos, abatidos);
	Interaccion::colision(jugador, disparos, vida);
	Interaccion::colision(jugador, enemigos, vida);
	Interaccion::colision(enemigos);
	
	camara.setPos(jugador.getPos().x, jugador.getPos().y);
}

void Mundo::inicializa()
{
	nivel = 0;

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
	vida = 6;// temporal
	nivel++;
	jugador.setPos(0, 0);//Posicion inicial, comun para todos los niveles

	//Destruir cosas
	enemigos.destruirContenido();
	disparos.destruirContenido();
	mapa.destruirContenido();  //Hay que corregirlo para que se destruyan

	if (nivel == 1)
	{
		//Nivel 1

		for (int i = 0; i < 4; i++) {
			Enemigo* e = new Enemigo();
			e->setPos(15 + 2 * i, 15 + 2 * i);
			enemigos.agregar(e);
		}

		jugador.setPos(-3, -3);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 2)
	{
		//Nivel 2
		for (int i = 0; i < 4; i++) {
			Enemigo* e = new Enemigo();
			e->setPos(30 + 3 * i, 15 + 3 * i);
			enemigos.agregar(e);
		}
		for (int i = 0; i < 4; i++) {
			Torreta* t = new Torreta();
			t->setPos(40, 10+i*10);
			enemigos.agregar(t);
		}

		jugador.setPos(20, 22);

		mapa.cargarBordes(nivel);
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
	ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}