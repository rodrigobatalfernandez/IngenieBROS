#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"

#define FIL 4 //filas del mapa
#define COL 4 //columnas del mapa

//variables globales
int mapa[FIL][COL]= {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	}; //matriz principal mapa

Mapa::Mapa() {
	/*suelo.setColor(0, 100, 0);
	suelo.setPos(-10.0f, 0, 10.0f, 0);

	techo.setColor(0, 100, 0);
	techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);

	pared_izda.setColor(0, 150, 0);
	pared_izda.setPos(10.0f, 0, 10.0f, 15.0f);*/

}


void Mapa::copia_nivel1() {
	//int matriz1[FIL][COL] = {
	//	{1,1,1,1},
	//	{1,1,1,1},
	//	{1,1,1,1},
	//	{1,1,1,1},
	//};
	//Copia la matriz1 a la matriz principal mapa
	//for (int f = 0; f < FIL; f++)
	//{
	//
	//	for (int c = 0; c < COL; c++)
	//	{
	//		mapa[f][c] = matriz1[f][c];
	//	}
	//}
}

void Mapa::dibuja() {
	//suelo.dibuja();
	//techo.dibuja();
	//pared_izda.dibuja();
	//pared_dcha.dibuja();

	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			
			if (mapa[fil][col] == 0) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/SovietChiquito.png").id);
				glDisable(GL_LIGHTING);
				glBegin(GL_POLYGON);
				glColor3f(1, 1, 1);
				glTexCoord2d(0, 1);    glVertex3f(-0.1+col-2, 0 + fil-2, -0.1);
				glTexCoord2d(1, 1);    glVertex3f(0.1 + col - 2, 0 + fil - 2, -0.1);
				glTexCoord2d(1, 0);    glVertex3f(0.1 + col - 2, 0.2 + fil - 2, -0.1);
				glTexCoord2d(0, 0);    glVertex3f(-0.1 + col - 2, 0.2+fil - 2, -0.1);
				glEnd();
				glEnable(GL_LIGHTING);
				glDisable(GL_TEXTURE_2D);
				
			}
			if (mapa[fil][col] == 1) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Bubble_Big.png").id);
				glDisable(GL_LIGHTING);
				glBegin(GL_POLYGON);
				glColor3f(1, 1, 1);
				glTexCoord2d(0, 1);    glVertex3f(-0.1 + col - 2, 0 + fil - 2, -0.1);
				glTexCoord2d(1, 1);    glVertex3f(0.1 + col - 2, 0 + fil - 2, -0.1);
				glTexCoord2d(1, 0);    glVertex3f(0.1 + col - 2, 0.2 + fil - 2, -0.1);
				glTexCoord2d(0, 0);    glVertex3f(-0.1 + col - 2, 0.2 + fil - 2, -0.1);
				glEnd();
				glEnable(GL_LIGHTING);
				glDisable(GL_TEXTURE_2D);

			}
		}
	}
}