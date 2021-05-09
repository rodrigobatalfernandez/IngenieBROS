#pragma once
#include "ETSIDI.H"
#include "Vector2D.h"

#include "Camara.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "Mapa.h"


class Mundo
{
private:
	Camara camara;
	Jugador jugador;
	Disparo disparo;
	Enemigo enemigo;
	Mapa mapa;

		/*ListaDisparos disparos;
		ListaEsferas esferas;
		Hombre hombre;
		Caja caja;
		Bonus bonus;
		Pared plataforma;*/
public:
		~Mundo();
		void inicializa();
		void mueve();
		void dibuja();

		void teclaAbajo(unsigned char key);
		void teclaArriba(unsigned char key);
		void teclaEspecialAbajo(unsigned char key);
		void teclaEspecialArriba(unsigned char key);

		void musica();
};