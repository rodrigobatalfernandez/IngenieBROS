#include "Interaccion.h"


bool Interaccion::colision(Jugador& j, Pared p) {
	return true;
}

bool Interaccion::colision(Enemigo& e, Pared p) {
	return true;
}

bool Interaccion::colision(Disparo& d, Pared p) {
	return true;
}

bool Interaccion::colision(Jugador& j, Enemigo& e) {
	return true;
}

bool Interaccion::colision(Disparo& d, Enemigo& e) {
	return true;
}

bool Interaccion::colision(Disparo& d, Jugador& j) {
	float dis = (d.posicion - j.posicion).modulo() - d.radio;
	return true;
}