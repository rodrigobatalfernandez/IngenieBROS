#include "Mapa.h"

Mapa::Mapa() {
	suelo.setColor(0, 100, 0);
	suelo.setPos(-10.0f, 0, 10.0f, 0);

	techo.setColor(0, 100, 0);
	techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);

	pared_izda.setColor(0, 150, 0);
	pared_izda.setPos(10.0f, 0, 10.0f, 15.0f);
}

void Mapa::dibuja() {
	suelo.dibuja();
	techo.dibuja();
	pared_izda.dibuja();
	pared_dcha.dibuja();
}