#include "Interaccion.h"

bool Interaccion::colision(Jugador& j, Pared& p) {
	Vector2D dist;
	float dif = p.distancia(j.posicion, &dist) - j.radio;
	if (dif <= 0.0f) {
		j.posicion = j.posicion - dist * dif;
		return true;
	}
	return false;
}

bool Interaccion::colision(Enemigo& e, Pared& p) {
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f) {
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo& d, Pared& p) {
	Vector2D dir;
	float dif = p.distancia(d.posicion, &dir) - 2 * d.radio; //Se ha dejado como márgen de error el propio radio para un correcto reconocimiento de colisión
		if (dif <= 0.0f)
		{
			d.rebote--;
			Vector2D v_inicial = d.velocidad;
			d.velocidad = v_inicial - dir.unitario() * 2.0 * (v_inicial * dir);
			d.posicion = d.posicion - dir.unitario() * dif;
			d.sonido_disparo_impacto();
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

bool Interaccion::colision(Jugador& j, Disparo& d) {
	float dis = (d.posicion - j.posicion).modulo() - d.radio - j.radio;
	if (dis <= 0.0f) return true;
	return false;
}

bool Interaccion::colision(Enemigo& e1, Enemigo& e2) {
	Vector2D dis = e1.posicion - e2.posicion;
	if (dis.modulo() - e1.radio - e2.radio <= 0.0f) {
		e1.posicion = e1.posicion + dis * 0.1;
		e2.posicion = e2.posicion - dis * 0.1;
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INTERACCIONES DE LISTAS

void Interaccion::colision(Jugador& j, Mapa& mapa) {
	for (int i = mapa.getNumero() - 1; i >= 0; i--) {
		Interaccion::colision(j, *mapa[i]);
	}
}

void Interaccion::colision(ListaEnemigos& enemigos, Mapa& mapa) {
	for (int i = enemigos.getNumero() - 1; i >= 0; i--) {
		for (int j = mapa.getNumero() - 1; j >= 0; j--) {
			Interaccion::colision(*enemigos[i], *mapa[j]);
		}
	}
}

void Interaccion::colision(Jugador& j, ListaDisparos& disparos, int& vida) {
	for (int i = disparos.getNumero() - 1; i >= 0; i--) {
		if (Interaccion::colision(j, *disparos[i]))
			vida--;
	}
}

void Interaccion::colision(ListaDisparos& disparos, Mapa& mapa) {
	for (int i = disparos.getNumero() - 1; i >= 0; i--) {
		for (int j = mapa.getNumero() - 1; j >= 0; j--) {
			if (Interaccion::colision(*disparos[i], *mapa[j]))
				if (disparos[i]->getRebote() <= 0)
					disparos.eliminar(i);
		}
	}
}

void Interaccion::colision(ListaEnemigos& enemigos, ListaDisparos& disparos, int& abatidos) {
	for (int i = enemigos.getNumero()-1; i >= 0; i--) {
		for (int j = disparos.getNumero()-1; j >= 0; j--) {
			if (Interaccion::colision(*enemigos[i], *disparos[j])) {
				enemigos.eliminar(enemigos[i]);
				disparos.eliminar(disparos[j]);
				abatidos++;
			}
		}
	}
}

void Interaccion::colision(Jugador& j, ListaEnemigos& enemigos, int& vida) {
	for (int i = enemigos.getNumero() - 1; i >= 0; i--) {
		if (Interaccion::colision(j, *enemigos[i]))
			//enemigos.eliminar(enemigos[i]);
			vida--;
	}
}

void Interaccion::colision(ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNumero(); i++) {
		for (int j = i; j < enemigos.getNumero(); j++) {
			Interaccion::colision(*enemigos[i], *enemigos[j]);
		}
	}
}