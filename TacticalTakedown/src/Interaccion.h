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
	static bool colision(Jugador& j, Pared p);
	static bool colision(Enemigo& e, Pared p);
	static bool colision(Disparo& d, Pared p);

	//Colisiones ente objetos móviles
	static bool colision(Enemigo& e, Disparo& d);
	static bool colision(Jugador& j, Disparo& d);
	static bool colision(Jugador& j, Enemigo& e);

	//Colisiones con listas
	static void colision(Jugador& j, Mapa& mapa);
	static void colision(ListaEnemigos& enemigos, Mapa& mapa);
	static void colision(ListaDisparos& disparos, Mapa& mapa);
	static void colision(ListaEnemigos& enemigos, ListaDisparos& disparos);
	static void colision(Jugador& j, ListaDisparos& disparos);
	static void colision(Jugador& j, ListaEnemigos& enemigos);
};