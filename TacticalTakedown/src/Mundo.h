#pragma once
#include "Camara.h"
#include "Jugador.h"
#include "Mapa.h"
#include "Vector2D.h"
#include "ETSIDI.H"

class Mundo
{
private:
	Camara camara;
	Jugador jugador;
	Mapa mapa;

		/*ListaDisparos disparos;
		ListaEsferas esferas;
		Hombre hombre;
		Caja caja;
		Bonus bonus;
		Pared plataforma;*/
public:
		~Mundo();
		void tecla(unsigned char key);
		void inicializa();
		void rotarOjo();
		void mueve();
		void dibuja();
		void teclaEspecial(unsigned char key);
		void musica();
};