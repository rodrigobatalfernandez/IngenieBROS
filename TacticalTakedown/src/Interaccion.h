#pragma once
#include "Jugador.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "ListaEnemigos.h"
#include "Pared.h"
#include "Mapa.h"

class Interaccion {
public:
	//Colisiones contra las paredes
	static bool colision(Jugador& j, Pared p);	//Colisión entre jugador y pared
	static bool colision(Enemigo& e, Pared p);	//Colisión entre enemigo y pared
	static bool colision(Disparo& d, Pared p);	//Colisión entre disparo y pared

	//Colisiones con los disparos
	static bool colision(Enemigo& e, Disparo& d); //Colision entre jugador y enemigo
	static bool colision(Disparo& d, Jugador& j);

	static void colision(ListaEnemigos& enemigos, ListaDisparos& disparos);

	static bool colision(Jugador& j, Enemigo& e); //Colision entre jugador y enemigo
};