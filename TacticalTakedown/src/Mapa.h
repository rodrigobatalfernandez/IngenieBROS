#pragma once
#include "Pared.h"

#define MAX_PAREDES 10000


class Mapa {
private:
	Pared* lista[MAX_PAREDES];
	int numero;
	Pared pared[MAX_PAREDES];//borde_arriba, borde_abajo, borde_izq, borde_dcha;
	int FIL = 0, COL = 0;
	int mapa[100][100];

public:
	Mapa();
	virtual ~Mapa() { destruirContenido(); }
	int getNumero() { return numero; }

	bool agregar(Pared* e);
	void dibujaBordes();
	void destruirContenido();
	Pared* operator [](int i);

	void dibuja();
	void copia_nivel(int nivel);
	void textura(int fil, int col, float altura, char const* cadena1);
	void cargarBordes(int nivel);
	void cargaFondo(char const* cadena1, float altura=-0.2); //---------Para poner un fondo de nivel--------

	int** leerMatrices(const char* fileName);

	friend class Interaccion;
};