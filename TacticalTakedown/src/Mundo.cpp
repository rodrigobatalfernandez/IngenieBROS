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
	//mapa.dibujaBordes();
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
	disparos_enemigos.destruirContenido();
}

bool Mundo::cargarNivel()
{
	vida = 6;// temporal
	nivel++;
	//jugador.setPos(0, 0);//Posicion inicial, comun para todos los niveles
	
	jugador.setVel(0, 0);
	//Destruir cosas
	enemigos.destruirContenido();
	disparos.destruirContenido();
	disparos_enemigos.destruirContenido();
	mapa.destruirContenido();

	if (nivel == 1)
	{
		ETSIDI::stopMusica();
		//Nivel 1
		ETSIDI::playMusica("sonidos/DiffBAJO.mp3", true);//musica nivel 1
		enemigos.cargarEnem(nivel);

		jugador.setPos(22.5, 18);
		jugador.setOri(270);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 2)
	{
		ETSIDI::stopMusica();
		//Nivel 2
		ETSIDI::playMusica("sonidos/JasonMraz93Milles.mp3", true);//musica nivel 2
		enemigos.cargarEnem(nivel);

		jugador.setPos(-7.5, 2.7);

		mapa.cargarBordes(nivel);
	}
	if (nivel == 3)
	{

		//Nivel 3
		ETSIDI::stopMusica();
		ETSIDI::playMusica("sonidos/Soviet.mp3", true);//musica nivel 3

		enemigos.cargarEnem(nivel);

		jugador.setPos(37.5, -7);

		mapa.cargarBordes(nivel);
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::dibuja_corazones() {
	using namespace std;
	int vida_m = vida;
	int vida_v = 0;
	int resto = 0;
	int pos = -17;
	int y = 12;
	vida_v = vida_m / 2;
	resto = vida_m % 2;
	Vector2D aux = getCam();
	glTranslatef(aux.x, aux.y, 2);

	for (int i = 0; i < vida_v; i++) //imprime corazones enteros
	{
		glTranslatef(pos, y, 10);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 0);
		animacion.draw();
		//glRotatef(-orientacion, 0, 0, 1);
		glTranslatef(-pos, -y, -10);
		pos += 2;
	}
	if (resto == 1) //imprime corazones a la mitad solo 1
	{
		glTranslatef(pos, y, 10);
		//glRotatef(90, 0, 0, 1);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 1);
		animacion.draw();
		//glRotatef(-orientacion, 0, 0, 1);
		glTranslatef(-pos, -y, -10);
		pos += 2;
	}
	for (int i = 0; i < (CORAZONES - vida_v - resto); i++) { //imprime corazones vacios

		glTranslatef(pos, y, 10);
		//glRotatef(90, 0, 0, 1);
		ETSIDI::SpriteSequence animacion("imagenes/he.png", 3, 1, 50, true, 0, 0, 1 * ESCALA, 1 * ESCALA, 2);
		animacion.draw();
		//glRotatef(-orientacion, 0, 0, 1);
		glTranslatef(-pos, -y, -10);
		pos += 2;

	}
	//	glRotatef(-90, 1, 1, 1);
	glTranslatef(-aux.x, -aux.y, -2);
	cout << resto << "  " << vida << endl;

}