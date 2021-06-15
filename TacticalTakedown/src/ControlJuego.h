#pragma once
#include "Mundo.h"

class ControlJuego{
protected:
	//Estados del Juego
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA, CONTROLES, HISTORIA, COLOR };
	Estado estado;

	//Mundo sobre el que se va a trabajar
	Mundo mundo;

	//Progreso en las pantallas de historia
	int historia = 0;
	//Configuraci�n est�tica
	int color = 0;

public:
	ControlJuego();
	virtual ~ControlJuego();

	void mueve();
	void dibuja();
	void teclaAbajo(unsigned char key);
	void teclaArriba(unsigned char key);
	void teclaEspecialAbajo(unsigned char key);
	void teclaEspecialArriba(unsigned char key);

	//Modifica Mundo en funci�n de car�cteres particulares
	int posicionOK(int nivel);

	//Gestiona el di�logo de la historia
	void dialogo(char const* cadena = "imagenes/mgs_Sanders.png");	
};

