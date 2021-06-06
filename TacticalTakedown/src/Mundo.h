#pragma once
#include "ETSIDI.H"
#include "Vector2D.h"

#include "Camara.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Mapa.h"
#include "Pared.h"
#include "ListaParedes.h"
#include "Interaccion.h"
#include "Torreta.h"



class Mundo
{
private:
	Camara camara;
	Jugador jugador;
	ListaDisparos disparos;
	Enemigo enemigo;
	Mapa mapa;
	ListaParedes bordes;
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