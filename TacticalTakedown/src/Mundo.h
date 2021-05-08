#pragma once
#include "Camara.h"
#include "Jugador.h"

class Mundo
{
private:
	Camara camara;
	Jugador jugador;

		float x_ojo; //
		float y_ojo;
		float z_ojo;


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
};