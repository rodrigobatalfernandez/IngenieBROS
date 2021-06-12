#include "ControlJuego.h"

ControlJuego::ControlJuego()
{
	estado = INICIO;
}

ControlJuego::~ControlJuego() {}

void ControlJuego::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
		if (mundo.getEnem() == 0 /*&& posicionOK(mundo.getNum())*/)
		{
			estado = HISTORIA;
			if (!mundo.cargarNivel())
				estado = FIN;

		}
	}
}

void ControlJuego::dibuja()
{
	Vector2D aux = mundo.getCam();
	switch (estado)
	{
	case ControlJuego::INICIO:
		dialogo();

		glTranslatef(-3, -5, -10);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("TACTICAL TAKEDOWN", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA VER CONTROLES", -5, 5);

		ETSIDI::printxy("IngenieBROS", 2, 1);
		glTranslatef(3, 5, 10);

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
		dialogo();

		glTranslatef(-3, -5, -10);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		//Mostrar Puntuación y tiempo sobrevivido
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
		glTranslatef(3, 5, 10);

		break;
	case ControlJuego::PAUSA:
		mundo.dibuja();
		glTranslatef(aux.x, aux.y, 2);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA: Menu de pausa", -5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -P- para continuar", -5, 5);
		ETSIDI::printxy("Pulsa -I- para volver al inicio", -5, 4);

		glTranslatef(-aux.x, -aux.y, -2);
		break;
	case ControlJuego::CONTROLES:
		dialogo();

		glTranslatef(-7, -5, -10);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::printxy("CONTROLES: Menu de visualizacion de los controles", -5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -C- para volver al inicio", -5, 9);
		ETSIDI::printxy("Usa -ESPACIO- para disparar", -5, 6);
		ETSIDI::printxy("Usa FLECHA IZQ / DER para girar", -5, 4);
		ETSIDI::printxy("Usa -W A S D- para desplazarte", -5, 2);

		glTranslatef(3, 5, 10);
		break;
	case ControlJuego::HISTORIA:
		if (historia == 0)
		{
			dialogo();

			glTranslatef(-7, -5, -10);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::printxy("tu madre otra vez", -5, 10);
			glTranslatef(7, 5, 10);
		}
		else if (historia == 1)
		{
			dialogo();

			glTranslatef(-7, -5, -10);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::printxy("deja a mi madre en paz", -5, 10);
			glTranslatef(7, 5, 10);
		}
	default:
		break;
	}
}

void ControlJuego::dialogo(char const* cadena)
{
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(cadena).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f(-70 / 4, -3, 0);
	glTexCoord2d(1, 1);    glVertex3f(70 / 4, -3, 0);
	glTexCoord2d(1, 0);    glVertex3f(70 / 4, 21, 0);
	glTexCoord2d(0, 0);    glVertex3f(-70 / 4, 21, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void ControlJuego::teclaAbajo(unsigned char key)
{
	if (estado == INICIO)
	{
		historia = 0;
		if (key == 'e')
		{
			mundo.inicializa();
			estado = HISTORIA;
		}
		if (key == 's')
			exit(0);
		if (key == 'c')
			estado = CONTROLES;

	}
	else if (estado == JUEGO)
	{
		if (key == 'p')
		{
			estado = PAUSA;
		}
		else if (key == 'n')
			mundo.cargarNivel();
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
		else if (key != ' ')
			mundo.teclaAbajo(key);
		if ((key == 'i') || (key == 'I')) {
			estado = INICIO;
		}

	}
	else if (estado == CONTROLES)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == HISTORIA)
	{
		if (key == ' ' || key == 'e') {
			estado = JUEGO;
			historia++;
		}
	}
}

void ControlJuego::teclaArriba(unsigned char key)
{
	if ((estado == JUEGO) || (estado == PAUSA))
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

int ControlJuego::posicionOK(int nivel)
{
	//Devuelve 0 si no esta en ninguna posicion relevante
	//Devuelve 1 si esta en la posicion para salir del nivel
	//Devuelve 2 si esta en la posicion para curarse
	//Devuelve 3 si esta en la posicion para acelerar

	if (nivel == 1) {
		Vector2D salidaLimX(36, 39), salidaLimY(120, 129);
		if (mundo.getCam().x > 36 && mundo.getCam().x < 39 && mundo.getCam().y>120 && mundo.getCam().y < 129)
			return 1;
	}
	else if (nivel == 2) {
		Vector2D salidaLimX(36, 39), salidaLimY(120, 129);

		//Incluir posiciones chulas

		return 1;
	}
	else if (nivel == 3) {
		Vector2D salidaLimX(36, 39), salidaLimY(120, 129);

		//Salidas chulas

		return 1;
	}
	return 0;
}

