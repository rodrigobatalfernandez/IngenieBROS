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

void Mapa::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void Mapa::colision(Disparo d)
{
	for (int i = 0; i < numero; i++)
		Interaccion::colision(d, *(lista[i]));
}

void Mapa::colision(Jugador j)
{
	for (int i = 0; i < numero; i++)
		Interaccion::colision(j, *(lista[i]));
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

void Mapa::copia_nivel1() {
	int matriz1[FIL][COL] = {
		{0,0,0,0,0,0},
		{0,1,1,1,1,0},
		{0,1,1,2,1,0},
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

void Mapa::dibuja(Jugador& jugador, Enemigo& enemigo) { //falta , ListaDisparos& disparos

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

				//se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
					pared[(fil * 4) + (col * 4) ].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					pared[(fil * 4) + (col * 4)].dibuja();
					pared[(fil * 4) + (col * 4) + 1].setPos((-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					pared[(fil * 4) + (col * 4)+1].dibuja();
					pared[(fil * 4) + (col * 4) + 2].setPos((-3.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-3.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					pared[(fil * 4) + (col * 4)+2].dibuja();
					pared[(fil * 4) + (col * 4) + 3].setPos((-2.0f + col) * ESCALA, (0.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA, (-2.0f + col) * ESCALA, (1.0f + fil - fil + 1) * ESCALA + (fil - 4) * ESCALA);
					pared[(fil * 4) + (col * 4)+3].dibuja();

					//for (int i = 0; i < 4; i++) {
					//	//bordes.agregar(&(pared[i]));
					//	pared[i].dibuja();
					//}

				Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)]);
				Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+1]);
				Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+2]);
				Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+3]);

				Interaccion::colision(enemigo, pared[(fil * 4) + (col * 4)]);
				Interaccion::colision(enemigo, pared[(fil * 4) + (col * 4) + 1]);
				Interaccion::colision(enemigo, pared[(fil * 4) + (col * 4) + 2]);
				Interaccion::colision(enemigo, pared[(fil * 4) + (col * 4) + 3]);


				//for (int i = 0; i < 4; i++) {
				//	Disparo* aux = disparos.colision(pared[i]); //Devuelve la dirección de aquell disparo que ha colisionado con la pared
				//	if (aux != 0 && (aux->getRebote() <= 0))	//si algún disparo ha colisionado y a este no le quedan rebotes
				//		disparos.eliminar(aux);
				//	aux;
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

void Mapa::cargarBordes(Jugador& jugador){
	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			//Pared pared[4];
			if (mapa[fil][col] == 0) { //textura correspondiente a 0

			////se crean cuatro paredes invisibles alrededor de cada textura para las interacciones
				//Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)]);
				//Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+1]);
				//Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+2]);
				//Interaccion::colision(jugador, pared[(fil * 4) + (col * 4)+3]);
			}
		}
	}
}