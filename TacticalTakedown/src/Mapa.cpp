#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdio.h>
#include <stdlib.h>

#define FIL 4 //filas del mapa
#define COL 4 //columnas del mapa
#define ESCALA 5 //escala de texturas

//variables globales
int mapa[FIL][COL]; //matriz principal mapa

Mapa::Mapa() {

}

//void clonarMatriz(int origen[FIL][COL], int destino[FIL][COL]) {
//	memcpy(destino, origen, sizeof(int) * FIL * COL);
//}

void Mapa::copia_nivel1() {
	int matriz1[FIL][COL] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	};
	//Copia la matriz1 a la matriz principal mapa
	//clonarMatriz(matriz1, mapa);
	//Copia la matriz1 a la matriz principal mapa
	for (int f = 0; f < FIL; f++)
	{
	
		for (int c = 0; c < COL; c++)
		{
			mapa[f][c] = matriz1[FIL-f-1][c]; //FIL-f-1 porque si no salen las filas traspuestas
		}
	}
}

void Mapa::dibuja() {
	
	copia_nivel1();

	//borde_arriba.dibuja();
	//borde_abajo.dibuja();
	//borde_izq.dibuja();
	//borde_dcha.dibuja();

	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			
			if (mapa[fil][col] == 0) { //Textura correspondiente a 0
				textura(fil, col, 0.3, "imagenes/HUDA.png");

				//Se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
				borde_abajo.setPos((-1.5f+col) * ESCALA, (1.5f+fil-FIL+1) * ESCALA, (-0.5f+col) * ESCALA, (1.5f+fil-FIL+1) * ESCALA);
				borde_arriba.setPos((-1.5f + col)* ESCALA, (2.5f + fil-FIL+1)* ESCALA, (-0.5f + col)* ESCALA, (2.5f + fil-FIL+1)* ESCALA);
				borde_izq.setPos((-1.5f + col)* ESCALA, (1.5f + fil-FIL+1) * ESCALA, (-1.5f + col)* ESCALA, (2.5f + fil-FIL+1)* ESCALA);
				borde_dcha.setPos((-0.5f + col)* ESCALA, (1.5f + fil-FIL+1)* ESCALA, (-0.5f + col)* ESCALA, (2.5f + fil-FIL+1)* ESCALA);

				borde_arriba.dibuja();
				borde_abajo.dibuja();
				borde_izq.dibuja();
				borde_dcha.dibuja();
			}
			if (mapa[fil][col] == 1) { //Textura correspondiente a 1
				textura(fil, col, -0.1, "imagenes/StoneFloorTexture_0.png");
			}
			if (mapa[fil][col] == 2) { //Textura correspondiente a 2
				textura(fil, col, -0.1, "imagenes/SovietChiquito.png");
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
	glTexCoord2d(0, 1);    glVertex3f((-1.5 + col) * ESCALA, (-1.5 + fil) * ESCALA, altura);
	glTexCoord2d(1, 1);    glVertex3f((-0.5 + col) * ESCALA, (-1.5 + fil) * ESCALA, altura);
	glTexCoord2d(1, 0);    glVertex3f((-0.5 + col) * ESCALA, (-0.5 + fil) * ESCALA, altura);
	glTexCoord2d(0, 0);    glVertex3f((-1.5 + col) * ESCALA, (-0.5 + fil) * ESCALA, altura);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}