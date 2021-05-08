#pragma once

class Mundo
{
private:
		float x_ojo;
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