#pragma once
#include "Caja.h" 
#include "Hombre.h" 
#include "Esfera.h" 
#include "Bonus.h" 
#include "Disparo.h" 

class Mundo{
public: 
	Disparo disparo;
	Esfera esfera;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;

	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
