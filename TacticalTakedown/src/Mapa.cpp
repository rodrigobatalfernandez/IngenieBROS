#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include"Interaccion.h"
//#include "ListaParedes.h"

#define FIL 6 //filas del mapa
#define COL 6 //columnas del mapa
#define ESCALA 5 //escala de texturas

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
		lista[i]=nullptr;
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
			{0,0,0,0,0,0},
			{0,1,1,1,1,0},
			{0,1,1,0,1,0},
			{0,1,0,2,1,0},
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
	if (nivel == 2) {
		int matriz2[FIL][COL] = {
			{1,1,1,1,1,1},
			{1,1,0,1,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
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


	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{

			if (mapa[fil][col] == 0) { //Textura correspondiente a 0
				textura(fil, col, 0.3, "imagenes/HUDA.png");
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
			if (mapa[fil][col] == 0) { //textura correspondiente a 0

				//se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
				pared[(fil * COL * 4) + (col * 4)].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);

				pared[(fil * COL * 4) + (col * 4) + 1].setPos((-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);

				pared[(fil * COL * 4) + (col * 4) + 2].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);

				pared[(fil * COL * 4) + (col * 4) + 3].setPos((-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);

				for (int i = 0; i < 4; i++) {
					agregar(&(pared[(fil * COL * 4) + (col * 4) + i]));
				}
			}
		}
	}
}
