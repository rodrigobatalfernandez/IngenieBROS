#include "Interaccion.h"

bool Interaccion::colision(Jugador& j, Pared p) {
	Vector2D dist;
	float dif = p.distancia(j.posicion, &dist) - j.radio;
	if (dif <= 0.0f) {
		j.posicion = j.posicion - dist * dif;
	return true;
	}
	return false;
}

bool Interaccion::colision(Enemigo& e, Pared p) {
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f) {
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo& d, Pared p) {
	Vector2D dir;
	float dif = p.distancia(d.posicion, &dir) - 2 * d.radio; //Se ha dejado como márgen de error el propio radio para un correcto reconocimiento de colisión
		if (dif <= 0.0f)
		{
			d.rebote--;
			Vector2D v_inicial = d.velocidad;
			d.velocidad = v_inicial - dir.unitario() * 2.0 * (v_inicial * dir);
			d.posicion = d.posicion - dir.unitario() * dif;
			return true;
		}
		return false;
}

bool Interaccion::colision(Jugador& j, Enemigo& e) {
	float dis = (j.posicion - e.posicion).modulo() - j.radio - e.radio;
	if (dis <= 0.0f) return true;
	return false;
}

bool Interaccion::colision(Enemigo& e, Disparo& d) {
	float dis = (d.posicion - e.posicion).modulo() - d.radio - e.radio;
	if (dis <= 0) return true;
	return false;
}

bool Interaccion::colision(Disparo& d, Jugador& j) {
	float dis = (d.posicion - j.posicion).modulo() - d.radio - j.radio;
	if (dis <= 0.0f) return true;
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INTERACCIONES DE LISTAS

void Interaccion::colision(ListaEnemigos& enemigos, ListaDisparos& disparos) {
	for (int i = enemigos.getNumero()-1; i >= 0; i--) {
		for (int j = disparos.getNumero()-1; j >= 0; j--) {
			if (Interaccion::colision(*enemigos[i], *disparos[j])) {
				enemigos.eliminar(enemigos[i]);
				disparos.eliminar(disparos[j]);
			}
		}
	}
}