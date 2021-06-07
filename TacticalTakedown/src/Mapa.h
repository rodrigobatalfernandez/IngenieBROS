#pragma once
#include "Disparo.h"
#include "Jugador.h"
#include "Pared.h"
#include "ListaDisparos.h"

#define MAX_PAREDES 100000


class Mapa {
private: //Para incluir los bordes en lista paredes necesitan ser punteros (Pared*)
	Pared* lista[MAX_PAREDES];
	int numero;
	Pared pared[MAX_PAREDES];//borde_arriba, borde_abajo, borde_izq, borde_dcha;
	//ListaParedes paredes;
public:
	Mapa();
	//virtual ~Mapa();
	float getNumero() { return numero; }

	bool agregar(Pared* e);
	void dibujaBordes();
	void destruirContenido();
	Pared* operator [](int i);

	void dibuja(); //falta , ListaDisparos& disparos
	void copia_nivel(int nivel);
	void textura(int fil, int col, float altura, char const* cadena1);
	void cargarBordes(int nivel);
	void cargaFondo(char const* cadena1, float altura=-0.2); //---------Para poner un fondo de nivel--------

	friend class Interaccion;
};