#include "ControlJuego.h"
#include "freeglut.h"

ControlJuego juego;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion

void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void OnKeyboardUp(unsigned char key, int x, int y);

void onSpecialKeyboardDown(int key, int x, int y);
void onSpecialKeyboardUp(int key, int x, int y); //cuando se levante una tecla especial

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Tactical Takedown");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);

	glutTimerFunc(20, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	
	glutKeyboardFunc(OnKeyboardDown);	//Para teclas alfanum?ricas
	glutKeyboardUpFunc(OnKeyboardUp);

	glutSpecialFunc(onSpecialKeyboardDown); //Para las teclas de flechas en concreto
	glutSpecialUpFunc(onSpecialKeyboardUp);
	
	glutIgnoreKeyRepeat(1);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	juego.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
	//poner aqui el c?digo de teclado
	juego.teclaAbajo(key);

	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t) {
	//poner aqui el c?digo de teclado
	juego.teclaArriba(key);

	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y) {
	juego.teclaEspecialAbajo(key);
}

void onSpecialKeyboardUp(int key, int x, int y)
{
	juego.teclaEspecialArriba(key);
}

void OnTimer(int value) {
	//poner aqui el c?digo de animacion
	juego.mueve();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}