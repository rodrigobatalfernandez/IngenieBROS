#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include"Interaccion.h"
#include "ListaParedes.h"

#define FIL 6 //filas del mapa
#define COL 6 //columnas del mapa
#define ESCALA 5 //escala de texturas

//variables globales
int mapa[FIL][COL]; //matriz principal mapa

Mapa::Mapa() {

}

void Mapa::copia_nivel1() {
	int matriz1[FIL][COL] = {
		{0,0,0,0,0,0},
		{0,1,1,1,1,0},
		{0,1,1,0,1,0},
		{0,1,1,2,1,0},
		{0,1,1,1,1,0},
		{0,0,0,0,0,0},
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

void Mapa::dibuja() {

	copia_nivel1();


	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{

			if (mapa[fil][col] == 0) { //Textura correspondiente a 0
				textura(fil, col, 0.3, "imagenes/HUDA.png");

				////Se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
				//pared[0].setPos((-3.0f + col) * ESCALA, (0.0f + fil - FIL + 1) * ESCALA + (FIL-4)*ESCALA, (-2.0f + col) * ESCALA, (0.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA);
				//pared[1].setPos((-3.0f + col) * ESCALA, (1.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA);
				//pared[2].setPos((-3.0f + col) * ESCALA, (0.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA, (-3.0f + col) * ESCALA, (1.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA);
				//pared[3].setPos((-2.0f + col) * ESCALA, (0.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - FIL + 1) * ESCALA + (FIL - 4) * ESCALA);

				//for (int i = 0; i < 4; i++) {
				//	//paredes.agregar(pared[i]);
				//	pared[i].dibuja();
				//}

			}
			if (mapa[fil][col] == 1) { //Textura correspondiente a 1
				textura(fil, col, -0.1, "imagenes/StoneFloorTexture_0.png");
			}
			if (mapa[fil][col] == 2) { //Textura correspondiente a 2
				textura(fil, col, 0, "imagenes/SovietChiquito.png");
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

void Mapa::cargarBordes(ListaParedes& bordes){
	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			Pared pared[4];
			if (mapa[fil][col] == 0) { //textura correspondiente a 0

			//se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
			pared[0].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
			pared[1].setPos((-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
			pared[2].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
			pared[3].setPos((-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);

				for (int i = 0; i < 4; i++) {
				bordes.agregar(&(pared[i]));
				pared[i].dibuja();
				}

			}
		}
	}
}