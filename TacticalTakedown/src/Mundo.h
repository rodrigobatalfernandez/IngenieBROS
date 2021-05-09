#pragma once
#include "Camara.h"
#include "Jugador.h"
#include "Vector2D.h"
#include "ETSIDI.H"

class Mundo
{
private:
	Camara camara;
	Jugador jugador;

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