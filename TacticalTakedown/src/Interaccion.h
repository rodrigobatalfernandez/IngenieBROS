#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "Listadisparos.h"
#include "Pared.h"
#include "Mapa.h"

class Interaccion {
public:
	//Colisiones contra las paredes
	static bool colision(Jugador& j, Pared p);	//Colisi�n entre jugador y pared
	static bool colision(Enemigo& e, Pared p);	//Colisi�n entre enemigo y pared
	static bool colision(Disparo& d, Pared p);	//Colisi�n entre disparo y pared

	//Colisiones con los disparos
	static bool colision(Disparo& d, Enemigo& e); //Colision entre jugador y enemigo
	static bool colision(Disparo& d, Jugador& j);

	static bool colision(Jugador& j, Enemigo& e); //Colision entre jugador y enemigo
};