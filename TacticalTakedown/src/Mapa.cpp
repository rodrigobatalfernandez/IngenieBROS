#include "Mapa.h"
#include "freeglut.h"
#include "ETSIDI.h"


#define ESCALA 5 //escala de texturas
#define  MAX 100

#include <iostream>
#include "fstream"
#include "string"
#pragma warning(disable:4996)

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
		FIL = 0; COL = 0;
		int** matrix1 = leerMatrices("Mapa1.txt");

		//Copia la matriz1 a la matriz principal mapa
		
		//cout << "Matriz 1: " << endl;
		for (int f = 0; f < FIL; f++)
		{

			for (int c = 0; c < COL; c++)
			{
				mapa[f][c] = matrix1[FIL - f - 1][c]; //FIL-f-1 porque si no salen las filas traspuestas
			}
			//cout << endl;
		}
		//delete matrix1;
	}
	else if (nivel == 2) {
		FIL = 0; COL = 0;
		int** matrix2 = leerMatrices("Mapa2.txt");

		//Copia la matriz1 a la matriz principal mapa
		for (int f = 0; f < FIL; f++)
		{

			for (int c = 0; c < COL; c++)
			{
				mapa[f][c] = matrix2[FIL - f - 1][c]; //FIL-f-1 porque si no salen las filas traspuestas
			}
		}
		//delete matrix2;
	}
	else if (nivel == 3) {
		FIL = 0; COL = 0;
		int** matrix3 = leerMatrices("Mapa3.txt");

		//Copia la matriz1 a la matriz principal mapa
		for (int f = 0; f < FIL; f++)
		{

			for (int c = 0; c < COL; c++)
			{
				mapa[f][c] = matrix3[FIL - f - 1][c]; //FIL-f-1 porque si no salen las filas traspuestas
			}
		}
		//delete matrix3;
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
				textura(fil, col, 0, "imagenes/Tiles/tile073.png");
			}
			else if (mapa[fil][col] == 29) { //Textura correspondiente a 29
				textura(fil, col, 0, "imagenes/Tiles/tile046.png");
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
				textura(fil, col, 0, "imagenes/Tiles/tile004.png");
			}
			else if (mapa[fil][col] == 35) { //Textura correspondiente a 35
				textura(fil, col, 0, "imagenes/Tiles/tile062.png");
			}
			else if (mapa[fil][col] == 36) { //Textura correspondiente a 36
				textura(fil, col, 0.2, "imagenes/Tiles/tile086.png");
			}
			else if (mapa[fil][col] == 37) { //Textura correspondiente a 37
			textura(fil, col, 0, "imagenes/Tiles/tile087.png");
			}
			else if (mapa[fil][col] == 38) { //Textura correspondiente a 38
				textura(fil, col, 0, "imagenes/Tiles/tile084.png");
			}
			else if (mapa[fil][col] == 39) { //Textura correspondiente a 39
				textura(fil, col, -0.1, "imagenes/Tiles/tile002.png");
			}
			else if (mapa[fil][col] == 40) { //Textura correspondiente a 40
				textura(fil, col, -0.1, "imagenes/Tiles/tile072.png");
			}
			else if (mapa[fil][col] == 41) { //Textura correspondiente a 41
				textura(fil, col, 0, "imagenes/Tiles/tile087.png");
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
	copia_nivel(nivel);
	for (int fil = 0; fil < FIL; fil++)
	{
		for (int col = 0; col < COL; col++)
		{
			int num = mapa[fil][col];
			if ((num == 1) || num == 2 || num == 3 || num == 4 || num == 28 || num == 29 || num == 36 || num == 37) { //texturas con colisiones

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
			num = 0;
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

int** Mapa::leerMatrices(const char* fileName) {
	char cadena[MAX]; //cadena para leer lineas, limitado por el numero max es 100 ahora, se puede modificar
	bool flag_inicio = 0;
	int num = 0;
	int j = 0;
	int k = 0;
	int cifra = 0;
	FILE* entrada;
	FIL = 0;
	COL = 0;

	int** matriz = NULL;//punto a matriz

	entrada = fopen(fileName, "r"); //se abre con fopen se necesita #pragma warning(disable:4996) para compilar
	if (entrada == NULL)

		printf("NO SE PUEDE ABRIR");
	else
	{
		fgets(cadena, 10, entrada); //Primer segmento, num columnas
		for (int n = 0; n < 2; n++) {
			if ((cadena[n] >= '0') && (cadena[n] <= '9')) {
				cifra = cadena[n] - 48; //char a int
				COL = COL * 10 + cifra;
			}

		}
		fgets(cadena, 10, entrada); //Segmento segunda fila, num filas

		for (int u = 0; u < 2; u++) {
			if ((cadena[u] >= '0') && (cadena[u] <= '9')) {

				cifra = cadena[u] - 48; //char a int
				FIL = FIL * 10 + cifra;
			}
		}
		matriz = new int* [FIL];//CREAMOS MATRIZ
		for (int i = 0; i <= FIL; i++) {
			matriz[i] = new int[COL];
		}
		j = k = 0;//reset variables 
		while (!feof(entrada))
		{

			fgets(cadena, MAX, entrada);
			for (int i = 0; i < MAX; i++) {
				if (j <= FIL && k <= COL)
				{

					if (cadena[i] == '{')//inicio fila
					{
						flag_inicio = 1;
						k = 0;
					}
					if ((cadena[i] >= '0') && (cadena[i] <= '9') && (flag_inicio == 1))
					{

						cifra = cadena[i] - 48; //char a int
						num = num * 10 + cifra; //2 cifras
						matriz[j][k] = num;

					}
					else if ((cadena[i] == ',') && (flag_inicio == 1)) {
						k++;
						num = 0;
					}
					else if ((cadena[i] == '}') && (flag_inicio == 1)) {//fin de linea
						j++;
						k = num = 0;
						flag_inicio = 0;
					}
				}

			}
		}
	}
	std::fclose(entrada);//cerramos fichero
	FIL++; COL++;
	return matriz;
}
