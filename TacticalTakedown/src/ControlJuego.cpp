#include "ControlJuego.h"

ControlJuego::ControlJuego()
{
	estado = INICIO;										//Tocame los huevos
}

ControlJuego::~ControlJuego(){}

void ControlJuego::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
	}
}

void ControlJuego::dibuja()
{
	Vector2D aux = mundo.getCam();
	switch (estado)
	{
	case ControlJuego::INICIO:
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);						//Bacon
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("IngenieBROS", 2, 1);
		break;
	case ControlJuego::JUEGO:
		mundo.dibuja();
		break;
	case ControlJuego::GAMEOVER:
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
		break;
	case ControlJuego::FIN:
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
		break;
	case ControlJuego::PAUSA:
		mundo.dibuja();
		glTranslatef(aux.x, aux.y, 2);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA: Menu de pausa", -5, 10);
		ETSIDI::printxy("Pulsa -P- para continuar", -5, 5);
		glTranslatef(-aux.x, -aux.y, -2);
		break;
	default:
		break;
	}
}

void ControlJuego::teclaAbajo(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		if (key == 'p')
		{
			estado = PAUSA;
		}
		mundo.teclaAbajo(key);
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA)
	{
		if ((key == 'p') || (key == 'P')) {
			estado = JUEGO;
		}
		else if(key != ' ')
			mundo.teclaAbajo(key);
	}
}

void ControlJuego::teclaArriba(unsigned char key)
{
	if ((estado == JUEGO) || (estado==PAUSA))
		mundo.teclaArriba(key);
}

void ControlJuego::teclaEspecialAbajo(unsigned char key)
{
	if ((estado == JUEGO) || (estado == PAUSA))
		mundo.teclaEspecialAbajo(key);
}

void ControlJuego::teclaEspecialArriba(unsigned char key)
{
	if ((estado == JUEGO) || (estado == PAUSA))
		mundo.teclaEspecialArriba(key);
}
