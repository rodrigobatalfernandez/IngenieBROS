#include "Mundo.h"
#include "freeglut.h"
#include <iostream>

#define PI 3.141592
#define ESCALA 3
#define CORAZONES 3

void Mundo::dibuja() 
{
	glEnable(GL_LIGHTING);	//Activa la iluminación previo al dibujo de objetos

	camara.dibuja();
	mapa.dibuja();
	dibuja_corazones();


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
	Interaccion::colision(jugador, disparos_enemigos, vida);
	Interaccion::colision(jugador, enemigos, vida);
	Interaccion::colision(enemigos);
	
	camara.setPos(jugador.getPos().x, jugador.getPos().y);
}

void Mundo::inicializa()
{
	nivel = 0;
	vida = VIDAS_INI;
	abatidos = 0;
	curado = false;
	recargado = false;
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

		jugador.dispara(disparos);
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
	disparos_enemigos.destruirContenido();
}

bool Mundo::cargarNivel()
{
	vida+=VIDAS_NIVEL;// temporal
	nivel++;
	//jugador.setPos(0, 0);//Posicion inicial, comun para todos los niveles
	
	jugador.setVel(0, 0);
	jugador.setVelAng(0);
	//Destruir cosas
	enemigos.destruirContenido();
	disparos.destruirContenido();
	disparos_enemigos.destruirContenido();
	mapa.destruirContenido();

	if (nivel == 1)
	{
		ETSIDI::stopMusica();
		//Nivel 1
		
		enemigos.cargarEnem(nivel);

		jugador.setPos(22.5, 18);
		jugador.setOri(270);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 2)
	{
		ETSIDI::stopMusica();
		//Nivel 2

		enemigos.cargarEnem(nivel);

		jugador.setPos(-7.5, 2.7);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 3)
	{

		//Nivel 3
		ETSIDI::stopMusica();

		enemigos.cargarEnem(nivel);

		jugador.setPos(37.5, -7);

		mapa.cargarBordes(nivel);
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::dibuja_corazones() {
	int vida_v = vida / 2;
	int resto = vida % 2;
	int pos = -17;
	const int y = 12;

	glTranslatef(getCam().x, getCam().y, 2);
	for (int i = 0; i < vida_v; i++) //imprime corazones enteros
	{
		glTranslatef(pos, y, 10);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 0);
		animacion.draw();
		glTranslatef(-pos, -y, -10);
		pos += 2;
	}
	if (resto == 1) //imprime corazones a la mitad solo 1
	{
		glTranslatef(pos, y, 10);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 1);
		animacion.draw();
		glTranslatef(-pos, -y, -10);
		pos += 2;
	}
	for (int i = 0; i < (CORAZONES - vida_v - resto); i++) { //imprime corazones vacios

		glTranslatef(pos, y, 10);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 2);
		animacion.draw();
		glTranslatef(-pos, -y, -10);
		pos += 2;

	}
	glTranslatef(-getCam().x, -getCam().y, -2);

}