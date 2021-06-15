#include "ControlJuego.h"
#include  <iostream>

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
		if (mundo.getEnem() == 0 && posicionOK(mundo.getNum())==1)
		{
			estado = HISTORIA;
			if (!mundo.cargarNivel())
				estado = FIN;
			//Si se quiere hacer todo en historia hay que variar esto

		}
		if (!mundo.getVida())
			estado = GAMEOVER;
	}
}

void ControlJuego::dibuja()
{
	Vector2D aux = mundo.getCam();
	const char col = color + 49;
	switch (estado)
	{
	case ControlJuego::INICIO:
		ETSIDI::stopMusica();
		glTranslatef(0, -1, -1);
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glTranslatef(3, 5, 10);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/laser_tank.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-12, 2, 0);
		glTexCoord2d(1, 1);    glVertex3f(6, 2, 0);
		glTexCoord2d(1, 0);    glVertex3f(6, 11, 0);
		glTexCoord2d(0, 0);    glVertex3f(-12, 11, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(-3, -5, -10);
		glTranslatef(0, 1, 1);

		glTranslatef(-5, -5.5, -10);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/METAG___.ttf", 20);
		ETSIDI::printxy("TACTICAL TAKEDOWN", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Tactical Espionage Action.ttf", 15);
		ETSIDI::printxy("PULSE LA TECLA  E  PARA EMPEZAR", -10, 6);
		ETSIDI::printxy("PULSE LA TECLA  S  PARA SALIR", -10, 5);
		ETSIDI::printxy("PULSE LA TECLA  C  PARA VER CONTROLES", -10, 4);
		ETSIDI::printxy("PULSE LA TECLA  A  PARA CAMBIAR EL ASPECTO", -10, 3);


		ETSIDI::printxy("IngenieBROS", 5, 0);
		glTranslatef(5, 5.5, 10);
	

		break;
	case ControlJuego::JUEGO:
		mundo.dibuja();
		break;
	case ControlJuego::GAMEOVER:
		//mundo.dibuja();
		dialogo();
		glTranslatef(-3, -5, -10);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
		glTranslatef(-3, -5, -10);

		break;
	case ControlJuego::FIN:
		dialogo();

		glTranslatef(-3, -5, -10);
		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		//Mostrar Puntuación y tiempo sobrevivido
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
		glTranslatef(3, 5, 10);

		break;
	case ControlJuego::PAUSA:
		mundo.dibuja();
		glTranslatef(aux.x, aux.y, 2);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);
		ETSIDI::printxy("PAUSA: Menu de pausa", -5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -P- para continuar", -5, 5);
		ETSIDI::printxy("Pulsa -I- para volver al inicio", -5, 4);

		glTranslatef(-aux.x, -aux.y, -2);
		break;
	case ControlJuego::CONTROLES:
		glTranslatef(0, -1, -1);
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glTranslatef(3, 5, 10);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/wasd.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-8, 4, 0);
		glTexCoord2d(1, 1);    glVertex3f(2, 4, 0);
		glTexCoord2d(1, 0);    glVertex3f(2, 11, 0);
		glTexCoord2d(0, 0);    glVertex3f(-8, 11, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(-3, -5, -10);
		glTranslatef(0, 1, 1);

		glTranslatef(-7, -5, -10);
		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::printxy("CONTROLES:", -5, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -C- para volver al inicio", -5, 9);
		ETSIDI::printxy("Usa -ESPACIO- para disparar", -5, 6);
		ETSIDI::printxy("Usa FLECHA IZQ / DER para girar", -5, 4);
		ETSIDI::printxy("Usa -W A S D- para desplazarte", -5, 2);

		glTranslatef(3, 5, 10);
		break;
	case ControlJuego::COLOR:
		//Texto para elegir color
		//Crear funcion en mundo
		//color tanque. 0-verde,1-rojo,2-amarillo,3-azul,4-morado,5-celeste,6-naranja,7-pink
		//ListaDisparos.cpp linea 18 revisar
		dialogo();


		glTranslatef(-7, -5, -10);


		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::printxy("SKINS: Menu de cambio de skin", -5, 11);
		ETSIDI::printxy("Color seleccionado;", -5, 10);
		ETSIDI::printxy(&col, 11, 10);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulsa -C- para volver al inicio", -5, 9);
		ETSIDI::printxy("Usa -1- para cambiar a verde", -5, 7);
		ETSIDI::printxy("Usa -2- para cambiar a rojo", -5, 6);
		ETSIDI::printxy("Usa -3- para cambiar a amarillo", -5, 5);
		ETSIDI::printxy("Usa -4- para cambiar a azul", -5, 4);
		ETSIDI::printxy("Usa -5- para cambiar a morado", -5, 3);
		ETSIDI::printxy("Usa -6- para cambiar a celeste", -5, 2);
		ETSIDI::printxy("Usa -7- para cambiar a naranja", -5, 1);
		ETSIDI::printxy("Usa -8- para cambiar a rosa", -5, 0);


		glTranslatef(3, 5, 10);

		break;
	case ControlJuego::HISTORIA:
		ETSIDI::setFont("fuentes/04B_11__.ttf", 16);

		if (historia == 0)
		{
			dialogo();
			glTranslatef(-7, -5, -10);
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::printxy("Coronel Sanders;", -10, 12);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::printxy("Python, no hay tiempo para explicaciones.", -10, 10);
			ETSIDI::printxy("Tienes una mision de vital importancia.", -10, 9);
			ETSIDI::printxy("Hemos preparado el tanque laser y en breve", -10, 7);
			ETSIDI::printxy("recibiras las coordenadas.", -10, 6);
			ETSIDI::printxy("Tendras que infiltrarte en la base militar", -10, 5);
			ETSIDI::printxy("de esa localizacion.", -10, 4);
			ETSIDI::printxy("El Doctor Jagger te dara mas indicaciones.", -10, 2);
			ETSIDI::printxy("Buena suerte, soldado.", -10, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("Pulsa E o ESPACIO para continuar", 10, -1);
		}
		else if (historia == 1)
		{
			dialogo("imagenes/mgs_doc1.png");
			glTranslatef(-7, -5, -10);
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::printxy("Doctor Jagger;", -10, 12);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::printxy("Al habla Jagger.", -10, 10);
			ETSIDI::printxy("He movido algunos hilos y, en la base de datos", -10, 9);
			ETSIDI::printxy("de sus instalaciones, he encontrado algunos", -10, 8);
			ETSIDI::printxy("de los investigadores con mayor IQ del pais", -10, 7);
			ETSIDI::printxy("(alguno fue a mi clase en el MIT).", -10, 6);
			ETSIDI::printxy("Por lo visto, han montado todo esto para", -10, 3);
			ETSIDI::printxy("purificar el mundo de la humanidad", -10, 2);
			ETSIDI::printxy("provocando una Tercera Guerra Mundial.", -10, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("Pulsa E o ESPACIO para continuar", 10, -1);
		}
		else if (historia == 2)
		{
			dialogo();
			glTranslatef(-7, -5, -10);
			ETSIDI::printxy("deja a mi madre en paz;", -5, 10);
		}
		else if (historia == 3)
		{
			dialogo();
			glTranslatef(-7, -5, -10);
			ETSIDI::printxy("deja a mi madre en paz", -5, 10);
			//Si esta historia es la de ganar la partida no va aqui
			//Si esta historia es la de perder la partida no va aqui
		}

		glTranslatef(7, 5, 10);
		break;
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
		if (key == 'a')
			estado = COLOR;

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
	else if (estado == COLOR)
	{
		if (key == 'c')
			estado = INICIO;
		else if ((key > '0') && (key < '9')) {
			color = key - 49;
			mundo.setColor(color);
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
		//Mejora: Poner centro del cuadrado de salida y meter margenes
		Vector2D salida(-10, 107.5);
		if(mundo.getCam().x > (salida.x-2.5) && mundo.getCam().x < (salida.x+2.5) && mundo.getCam().y> (salida.y-2.5) && mundo.getCam().y < (salida.y+2.5))
			return 1;
	}
	else if (nivel == 2) {
		Vector2D salida(36, 39), cura(1,1), acelerar(1,1);
		if (mundo.getCam().x > (salida.x - 2.5) && mundo.getCam().x < (salida.x + 2.5) && mundo.getCam().y>(salida.y - 2.5) && mundo.getCam().y < (salida.y + 2.5))
			return 1;
		if (mundo.getCam().x > (cura.x - 2.5) && mundo.getCam().x < (cura.x + 2.5) && mundo.getCam().y>(cura.y - 2.5) && mundo.getCam().y < (cura.y + 2.5))
			return 2;
		if (mundo.getCam().x > (acelerar.x - 2.5) && mundo.getCam().x < (acelerar.x + 2.5) && mundo.getCam().y>(acelerar.y - 2.5) && mundo.getCam().y < (acelerar.y + 2.5))
			return 3;
	}
	else if (nivel == 3) {
		Vector2D salida(-10, 107.5);
		if (mundo.getCam().x > (salida.x - 2.5) && mundo.getCam().x < (salida.x + 2.5) && mundo.getCam().y>(salida.y - 2.5) && mundo.getCam().y < (salida.y + 2.5))

		//Salidas chulas

		return 1;
	}
	return 0;
}

