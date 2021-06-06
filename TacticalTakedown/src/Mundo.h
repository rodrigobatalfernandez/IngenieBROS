#pragma once
#include "ETSIDI.H"
#include "Vector2D.h"

#include "Camara.h"
#include "ListaDisparos.h"
#include "Mapa.h"
#include "Pared.h"
#include "Interaccion.h"
#include "Torreta.h"
#include "ListaEnemigos.h"


class Mundo
{
private:
	Camara camara;
	Jugador jugador;
	ListaDisparos disparos, disparos_enemigos;
	ListaEnemigos enemigos;
	Enemigo enemigo;
	Mapa mapa;
	Pared pared[4];

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
		Vector2D getCam() { return camara.getPos(); }

		void musica();
};