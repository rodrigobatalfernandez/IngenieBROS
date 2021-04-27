#include "freeglut.h"
#include <math.h>

//Los callback son funciones que serán llamadas automáticamente por la glut cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);	//Esta función será llamada para dibujar
void OnTimer(int value);	//Esta función será llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);	//Esta función será llamada cuando se pulse una tecla	

struct esfera {		//Estructura para esferas, con todos los datos pertinentes bien clasificados
	float radio;
	float x, y, z;
	unsigned char rojo, verde, azul;
};
esfera esf1 = { 1, 0, 0, 0, 255, 255, 255 };
struct toro {
	float ri, re;
	float rojo, verde, azul;
};
toro tor1 = { 1, 5, 255, 255, 0 };
void cambiaToro(toro* tor);
struct tetera {
	float x, y, z;
	float rojo, verde, azul;
	float beta;
};
tetera tet1 = { 0, 1, 0, 255, 255, 255, 0 };
void mueveTetera(tetera* tet);
struct camara {		//Estructura de control de la cámara, com posición y punto de vista
	float x, y, z;
	float mx, my, mz;
};
camara cam = { 0, 10, 20, 0, 0, 0 };
void rotaCamara(camara* cam);
struct fondo {
	float a[3], b[3], c[3], d[3];
};
fondo suelo = { 255, 255, 255, 255, 0, 0, 0, 255, 0, 0, 0, 255 };

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	glutInit(&argc, argv);
	//Inicializa las especificaciones de la ventana y crea una con el nombre "MiJuego"
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//Habilita la iluminación y define la perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registra los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);	//se especifica que cada 25ms de ejecución llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//Pasa el control a GLUT, que llamará a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Define el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam.x, cam.y, cam.z,	//posición del ojo
		cam.mx, cam.my, cam.mz,	//hacia que punto mira
		0.0, 1.0, 0.0);   //se define referencia espacial (eje Y)    

//CÓDIGO DE DIBUJO AQUÍ	
//Suelo
	glBegin(GL_POLYGON);
	glColor3ub(suelo.a[0], suelo.a[1], suelo.a[2]);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glColor3ub(suelo.b[0], suelo.b[1], suelo.b[2]);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(suelo.c[0], suelo.c[1], suelo.c[2]);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(suelo.d[0], suelo.d[1], suelo.d[2]);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd();
	//Toro con cambio de color estroboscópico
	glColor3ub(tor1.rojo, tor1.verde, tor1.azul);
	glutSolidTorus(tor1.ri, tor1.re, 100, 100);
	//Tetera que va de esquina a esquina
	glColor3ub(tet1.rojo, tet1.verde, tet1.azul);
	glTranslated(tet1.x, tet1.y, tet1.z);
	glRotatef(tet1.beta, 0, 1, 0);
	glutSolidTeapot(1);
	glRotatef(-tet1.beta, 0, 1, 0);
	glTranslated(-tet1.x, -tet1.y, -tet1.z);
	//Esfera manipulable
	glTranslated(esf1.x, esf1.y, esf1.z);
	glColor3ub(esf1.rojo, esf1.verde, esf1.azul);
	glutWireSphere(esf1.radio, 20, 20);

	//NO BORRAR ESTA LÍNEA NI PONER NADA DESPUÉS
	glutSwapBuffers();	//redibuja la pantalla
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	switch (key) {
	case('w'):
		esf1.z--;
		break;
	case('a'):
		esf1.x--;
		break;
	case('s'):
		esf1.z++;
		break;
	case('d'):
		esf1.x++;
		break;
	case('r'):
		esf1.rojo = 255;
		esf1.verde = 0;
		esf1.azul = 0;
		break;
	case('g'):
		esf1.rojo = 0;
		esf1.verde = 255;
		esf1.azul = 0;
		break;
	case('b'):
		esf1.rojo = 0;
		esf1.verde = 0;
		esf1.azul = 255;
		break;
	case('+'):
		if (esf1.radio < 8)
			esf1.radio += 0.5f;
		break;
	case('-'):
		if (esf1.radio > 1)
			esf1.radio -= 0.5f;
		break;
	}

	//NO BORRAR
	glutPostRedisplay();	//notifica la necesidad de redibujar la pantalla
}

void OnTimer(int value)
{
	rotaCamara(&cam);
	cambiaToro(&tor1);
	mueveTetera(&tet1);

	//NO BORRAR
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();	//notifica la necesidad de redibujar la pantalla
}

void rotaCamara(camara* cam) {
	float dist = sqrt(cam->x * cam->x + cam->z * cam->z);
	float theta = atan2(cam->z, cam->x);

	theta += 0.05f;
	cam->x = dist * cos(theta);
	cam->z = dist * sin(theta);
}

void cambiaToro(toro* tor) {
	if (tor->rojo >= 255 && tor->azul < 255) {
		tor->verde--;
		if (tor->verde < 0)
			tor->verde = 0;
		tor->azul++;
	}
	else if (tor->azul >= 255 && tor->verde < 255) {
		tor->rojo--;
		if (tor->rojo < 0)
			tor->rojo = 0;
		tor->verde++;
	}
	else if (tor->verde >= 255 && tor->rojo < 255) {
		tor->azul--;
		if (tor->azul < 0)
			tor->azul = 0;
		tor->rojo++;
	}
	else {
		tor->rojo = 255;
		tor->verde = 255;
		tor->azul = 0;
	}
}

void mueveTetera(tetera* tet) {
	if (tet->x >= 5 && tet->z < 5)
		tet->z += 0.5f;
	else if (tet->x > -5 && tet->z >= 5)
		tet->x -= 0.5f;
	else if (tet->x <= -5 && tet->z > -5)
		tet->z -= 0.5f;
	else if (tet->x < 5 && tet->z <= -5)
		tet->x += 0.5f;
	else
		tet->x = tet->z = -5;

	tet->beta += 2.5f;
}