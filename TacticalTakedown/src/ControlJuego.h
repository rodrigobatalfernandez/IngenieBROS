#pragma once
#include "Mundo.h"

class ControlJuego
{
public:
	ControlJuego();
	virtual ~ControlJuego();

	void mueve();
	void dibuja();
	void dialogo(char const* cadena = "imagenes/mgs_Sanders.png");

	void teclaAbajo(unsigned char key);
	void teclaArriba(unsigned char key);
	void teclaEspecialAbajo(unsigned char key);
	void teclaEspecialArriba(unsigned char key);

	int posicionOK(int nivel);

protected:
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA, CONTROLES, HISTORIA, COLOR };
	Estado estado;
	Mundo mundo;
	int historia = 0;
};

