#include "Caja.h"

Caja::Caja() {

	techo.setColor(0, 255, 0);
	suelo.setColor(0, 50, 0);
	pared_dcha.setColor(0, 150, 0);
	pared_izda.setColor(0, 150, 0);

	techo.limite1.x = suelo.limite1.x = pared_izda.limite1.x = pared_izda.limite2.x = -10;
	techo.limite1.y = techo.limite2.y = pared_dcha.limite1.y = pared_izda.limite2.y = 15;
	techo.limite2.x = suelo.limite2.x = pared_dcha.limite1.x = pared_dcha.limite2.x = 10;
	suelo.limite1.y = suelo.limite2.y = pared_dcha.limite2.y = pared_izda.limite1.y = 0;
}

void Caja::dibuja(){
	suelo.dibuja();
	techo.dibuja();
	pared_izda.dibuja();
	pared_dcha.dibuja();
}