#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include"Interaccion.h"
//#include "ListaParedes.h"

#define FIL 31 //filas del mapa
#define COL 30 //columnas del mapa
#define ESCALA 4 //escala de texturas

//#include <iostream>
//#include "fstream"
//#include "string"
//
//#define  MAX 128

//variables globales
int mapa[FIL][COL]; //matriz principal mapa

Mapa::Mapa() {
	numero = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		lista[i] = nullptr;
}

bool Mapa::agregar(Pared* p)
{
	if (numero < MAX_PAREDES) {
		for (int i = 0; i < numero; i++) {
			if (p == lista[i])
				return false; // la pared ya se encuentra en la lista
		}
		lista[numero++] = p; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;	// operación exitosa
}

void Mapa::dibujaBordes()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}


void Mapa::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

Pared* Mapa::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void Mapa::copia_nivel(int nivel) {
	if (nivel == 1) {
		int matriz1[FIL][COL] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,2,2,3,4,2,2,2,4,2,2,3,3,2,2,2,2,4,2,1},
{1,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,6,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,13,12,12,12,14,0,0,13,12,12,12,14,0,0,0,0,11,1},
{1,9,11,1,1,1,9,0,0,11,1,1,1,9,0,0,0,0,11,1},
{1,9,11,2,3,2,9,0,0,11,4,2,3,9,0,0,0,0,11,1},
{1,9,16,10,10,10,15,0,0,16,10,10,10,15,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,13,12,12,12,14,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,11,1,1,1,9,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,11,2,4,2,9,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,16,10,10,10,15,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,13,12,12,12,14,0,0,13,12,12,12,14,0,11,1},
{1,9,0,0,0,11,1,1,1,9,0,0,11,1,1,1,9,0,11,1},
{1,9,0,0,0,11,2,4,2,9,0,0,11,2,2,2,9,0,11,1},
{1,9,0,0,0,16,10,10,10,15,0,0,16,10,10,10,15,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,13,12,12,12,14,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,11,1,1,1,9,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,11,2,4,2,9,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,16,10,10,10,15,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
{1,8,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,7,1},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},


		};

		//Copia la matriz1 a la matriz principal mapa
		for (int f = 0; f < FIL; f++)
		{

			for (int c = 0; c < COL; c++)
			{
				mapa[f][c] = matriz1[FIL - f - 1][c]; //FIL-f-1 porque si no salen las filas traspuestas
			}
		}
	}
	else if (nivel == 2) {
		int matriz2[FIL][COL] = {
{17,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,17,17,},
{1,1,5,10,10,10,10,10,10,10,10,10,10,10,10,6,1,17,17,},
{1,32,24,0,13,12,12,14,13,12,12,14,0,0,0,11,1,17,17,},
{2,1,9,0,11,1,1,9,11,3,2,9,0,0,0,11,2,1,1,},
{17,1,9,0,11,3,2,9,16,10,10,15,0,0,0,11,33,34,1,},
{17,1,9,0,16,10,10,15,16,0,0,13,12,12,14,11,2,2,2,},
{17,1,8,12,12,12,12,12,14,0,0,11,1,1,9,11,1,17,17,},
{17,1,1,31,1,2,2,1,1,0,0,11,4,4,9,11,1,17,17,},
{17,17,1,34,1,17,17,1,9,0,0,16,10,10,15,11,2,1,1,},
{17,17,2,2,2,1,2,2,9,0,0,0,0,0,0,11,33,34,1,},
{17,17,17,17,17,1,19,17,24,0,0,0,0,0,0,11,2,2,2,},
{17,17,17,17,17,1,19,1,8,12,12,12,12,12,12,7,1,17,17,},
{17,17,17,17,17,1,19,1,2,2,2,2,2,2,2,2,2,17,17,},
{17,17,17,17,17,1,19,1,17,17,17,17,17,17,17,17,17,17,17,},
{17,17,17,17,17,1,19,2,2,3,2,2,3,2,4,2,1,17,17,},
{17,17,17,17,17,1,19,28,5,18,6,28,5,18,6,28,1,17,17,},
{17,17,17,17,17,1,8,18,7,29,8,18,7,29,8,22,1,17,17,},
{17,17,17,17,17,2,2,2,2,2,2,2,2,2,1,19,1,17,17,},
{17,17,17,17,17,17,17,17,17,17,17,17,17,17,1,19,1,17,17,},
{17,17,17,17,17,1,1,1,17,17,1,2,2,2,2,19,2,1,17,},
{17,17,17,17,1,2,30,2,1,17,1,5,10,10,10,27,6,1,17,},
{17,17,17,17,1,5,27,6,1,17,1,9,13,12,12,14,7,1,17,},
{17,17,17,17,1,8,26,7,1,17,1,9,11,3,4,19,28,1,17,},
{17,17,17,17,1,1,19,2,2,2,2,9,16,18,10,15,6,1,17,},
{17,17,17,17,17,1,20,18,18,18,18,24,11,28,9,0,11,1,17,},
{17,17,17,17,17,2,2,2,2,2,1,8,12,18,12,12,7,1,17,},
{17,17,17,17,17,17,17,17,17,17,2,2,2,2,2,2,2,2,17,},

		};

		//Copia la matriz1 a la matriz principal mapa
		for (int f = 0; f < FIL; f++)
		{

			for (int c = 0; c < COL; c++)
			{
				mapa[f][c] = matriz2[FIL - f - 1][c]; //FIL-f-1 porque si no salen las filas traspuestas
			}
		}
	}
}

void Mapa::dibuja() {
	//---------Para poner un fondo de nivel--------
	//cargaFondo("imagenes/Tiles/tile084.png");

	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{

			if (mapa[fil][col] == 0) { //Textura correspondiente a 0
				textura(fil, col, -0.1, "imagenes/Tiles/tile020.png");
			}
			else if (mapa[fil][col] == 1) { //Textura correspondiente a 1
				textura(fil, col, 0, "imagenes/Tiles/tile084.png");
			}
			else if (mapa[fil][col] == 2) { //Textura correspondiente a 2
				textura(fil, col, 0, "imagenes/Tiles/tile042.png");
			}
			else if (mapa[fil][col] == 3) { //Textura correspondiente a 3
				textura(fil, col, 0, "imagenes/Tiles/tile043.png");
			}
			else if (mapa[fil][col] == 4) { //Textura correspondiente a 4
				textura(fil, col, 0, "imagenes/Tiles/tile044.png");
			}
			else if (mapa[fil][col] == 5) { //Textura correspondiente a 5
				textura(fil, col, -0.1, "imagenes/Tiles/tile005.png");
			}
			else if (mapa[fil][col] == 6) { //Textura correspondiente a 6
				textura(fil, col, -0.1, "imagenes/Tiles/tile007.png");
			}
			else if (mapa[fil][col] == 7) { //Textura correspondiente a 7
				textura(fil, col, -0.1, "imagenes/Tiles/tile035.png");
			}
			else if (mapa[fil][col] == 8) { //Textura correspondiente a 8
				textura(fil, col, -0.1, "imagenes/Tiles/tile033.png");
			}
			else if (mapa[fil][col] == 9) { //Textura correspondiente a 9
				textura(fil, col, -0.1, "imagenes/Tiles/tile019.png");
			}
			else if (mapa[fil][col] == 10) { //Textura correspondiente a 10
				textura(fil, col, -0.1, "imagenes/Tiles/tile006.png");
			}
			else if (mapa[fil][col] == 11) { //Textura correspondiente a 11
				textura(fil, col, -0.1, "imagenes/Tiles/tile021.png");
			}
			else if (mapa[fil][col] == 12) { //Textura correspondiente a 12
				textura(fil, col, -0.1, "imagenes/Tiles/tile034.png");
			}
			else if (mapa[fil][col] == 13) { //Textura correspondiente a 13
				textura(fil, col, -0.1, "imagenes/Tiles/tile008.png");
			}
			else if (mapa[fil][col] == 14) { //Textura correspondiente a 14
				textura(fil, col, -0.1, "imagenes/Tiles/tile009.png");
			}
			else if (mapa[fil][col] == 15) { //Textura correspondiente a 15
				textura(fil, col, -0.1, "imagenes/Tiles/tile023.png");
			}
			else if (mapa[fil][col] == 16) { //Textura correspondiente a 16
				textura(fil, col, -0.1, "imagenes/Tiles/tile022.png");
			}
			else if (mapa[fil][col] == 17) { //Textura correspondiente a 17
				//textura(fil, col, -0.1, "imagenes/Tiles/tile017.png");  //Puede ponerse un tile de oscuridad o dejarlo vacío
			}
			else if (mapa[fil][col] == 18) { //Textura correspondiente a 18
				textura(fil, col, -0.1, "imagenes/Tiles/tile032.png");
			}
			else if (mapa[fil][col] == 19) { //Textura correspondiente a 19
				textura(fil, col, -0.1, "imagenes/Tiles/tile018.png");
			}
			else if (mapa[fil][col] == 20) { //Textura correspondiente a 20
				textura(fil, col, -0.1, "imagenes/Tiles/tile024.png");
			}
			else if (mapa[fil][col] == 21) { //Textura correspondiente a 21
				textura(fil, col, -0.1, "imagenes/Tiles/tile025.png");
			}
			else if (mapa[fil][col] == 22) { //Textura correspondiente a 22
				textura(fil, col, -0.1, "imagenes/Tiles/tile011.png");
			}
			else if (mapa[fil][col] == 23) { //Textura correspondiente a 23
				textura(fil, col, -0.1, "imagenes/Tiles/tile010.png");
			}
			else if (mapa[fil][col] == 24) { //Textura correspondiente a 24
				textura(fil, col, -0.1, "imagenes/Tiles/tile037.png");
			}
			else if (mapa[fil][col] == 25) { //Textura correspondiente a 25
				textura(fil, col, -0.1, "imagenes/Tiles/tile039.png");
			}
			else if (mapa[fil][col] == 26) { //Textura correspondiente a 26
				textura(fil, col, -0.1, "imagenes/Tiles/tile036.png");
			}
			else if (mapa[fil][col] == 27) { //Textura correspondiente a 27
				textura(fil, col, -0.1, "imagenes/Tiles/tile038.png");
			}
			else if (mapa[fil][col] == 28) { //Textura correspondiente a 28
				textura(fil, col, -0.1, "imagenes/Tiles/tile073.png");
			}
			else if (mapa[fil][col] == 29) { //Textura correspondiente a 29
				textura(fil, col, -0.1, "imagenes/Tiles/tile046.png");
			}
			else if (mapa[fil][col] == 30) { //Textura correspondiente a 30
				textura(fil, col, -0.1, "imagenes/Tiles/tile000.png");
			}
			else if (mapa[fil][col] == 31) { //Textura correspondiente a 31
				textura(fil, col, -0.1, "imagenes/Tiles/tile001.png");
			}
			else if (mapa[fil][col] == 32) { //Textura correspondiente a 32
				textura(fil, col, -0.1, "imagenes/Tiles/tile014.png");
			}
			else if (mapa[fil][col] == 33) { //Textura correspondiente a 33
				textura(fil, col, -0.1, "imagenes/Tiles/tile015.png");
			}
			else if (mapa[fil][col] == 34) { //Textura correspondiente a 34
			textura(fil, col, 0, "imagenes/Tiles/tile046.png");
			}
		}
	}
}

void Mapa::textura(int fil, int col, float altura, char const* cadena1)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(cadena1).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f((-3 + col) * ESCALA, (-3 + fil) * ESCALA, altura);
	glTexCoord2d(1, 1);    glVertex3f((-2 + col) * ESCALA, (-3 + fil) * ESCALA, altura);
	glTexCoord2d(1, 0);    glVertex3f((-2 + col) * ESCALA, (-2 + fil) * ESCALA, altura);
	glTexCoord2d(0, 0);    glVertex3f((-3 + col) * ESCALA, (-2 + fil) * ESCALA, altura);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Mapa::cargarBordes(int nivel) {
	if (nivel == 1)
		copia_nivel(nivel);
	else if (nivel == 2)
		copia_nivel(nivel);
	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			//Pared pared[4];
			if (mapa[fil][col] == 1 || mapa[fil][col] == 2 || mapa[fil][col] == 3 || mapa[fil][col] == 4 || mapa[fil][col] == 28 || mapa[fil][col] == 29) { //texturas con colisiones

				//se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
				Pared* p1 = new Pared;
					p1->setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					agregar(p1);
				Pared* p2 = new Pared;
					 p2->setPos((-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					 agregar(p2);
				 Pared* p3 = new Pared;
					p3->setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					agregar(p3);
				Pared* p4 = new Pared;
					p4->setPos((-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					agregar(p4);
			}
		}
	}
}

void Mapa::cargaFondo(char const* cadena1, float altura)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(cadena1).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f((-300) * ESCALA, (300) * ESCALA, altura);
	glTexCoord2d(1, 1);    glVertex3f((200) * ESCALA, (300) * ESCALA, altura);
	glTexCoord2d(1, 0);    glVertex3f((200) * ESCALA, (-200) * ESCALA, altura);
	glTexCoord2d(0, 0);    glVertex3f((-300) * ESCALA, (-200) * ESCALA, altura);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


