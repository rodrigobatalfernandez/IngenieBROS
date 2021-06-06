#pragma once
#include "Mundo.h"


class ControlJuego
{
public:
	ControlJuego();
	virtual ~ControlJuego();

	void mueve();
	void dibuja();

	void teclaAbajo(unsigned char key);
	void teclaArriba(unsigned char key);
	void teclaEspecialAbajo(unsigned char key);
	void teclaEspecialArriba(unsigned char key);

protected:
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	Mundo mundo;



};

