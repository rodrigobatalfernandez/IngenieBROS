#include "Mundo.h"
#include "freeglut.h"
#include <iostream>

#define PI 3.141592

void Mundo::dibuja() 
{
	glEnable(GL_LIGHTING);	//Activa la iluminación previo al dibujo de objetos

	camara.dibuja();
	mapa.dibuja();
	//mapa.dibujaBordes();

	jugador.dibuja();
	enemigos.dibuja();

	disparos.dibuja(1);
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
	case ('l'):
		std::cout << (jugador.getPos()).x << "  " << (jugador.getPos()).y << std::endl;

		break;
	case (' '):
		Disparo* d = new Disparo();
		//d->Tex();
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
	//jugador.setPos(0, 0);//Posicion inicial, comun para todos los niveles
	

	//Destruir cosas
	enemigos.destruirContenido();
	disparos.destruirContenido();
	mapa.destruirContenido();

	if (nivel == 1)
	{
		//Nivel 1

		enemigos.cargarEnem(nivel);

		jugador.setPos(22.5, 18);
		jugador.setOri(270);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 2)
	{
		//Nivel 2

		enemigos.cargarEnem(nivel);

		jugador.setPos(-7.5, 2.7);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 3)
	{
		//Nivel 3

		enemigos.cargarEnem(nivel);

		jugador.setPos(37.5, -7);

		mapa.cargarBordes(nivel);
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::musica() {//funcion musica, es necesaria pararlo
	ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);
}