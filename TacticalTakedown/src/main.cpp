#include "freeglut.h"

//Los callback son funciones que serán llamadas automáticamente por la glut cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);	//Esta función será llamada para dibujar
void OnTimer(int value);	//Esta función será llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);	//Esta función será llamada cuando se pulse una tecla	

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
	gluLookAt(0.0, 10, 20,	//posición del ojo
		0.0, 0, 0.0,	//hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);   //se define referencia espacial (eje Y)    

//CÓDIGO DE DIBUJO AQUÍ
	glutSolidTeapot(2);
	glutWireCube(6);
	//glutWireSphere(radius, slices, stacks);
	//glutSolidSphere(radius, slices, stacks);
	//glutWireCone(base, height, slices, stacks);
	//glutSolidCone(base, height, slices, stacks);
	//glutWireCube(size);
	//glutSolidCube(size);
	//glutWireTorus(innerRadius, outerRadius, sides, rings);
	//glutSolidTorus(innerRadius, outerRadius, sides, rings);
	//glutWireDodecahedron();
	//glutSolidDodecahedron();
	//glutWireTeapot(size);
	//glutSolidTeapot(size);
	//glutWireOctahedron();
	//glutSolidOctahedron();
	//glutWireTetrahedron();
	//glutSolidTetrahedron();
	//glutWireIcosahedron();
	//glutSolidIcosahedron();

	//NO BORRAR ESTA LÍNEA NI PONER NADA DESPUÉS
	glutSwapBuffers();	//redibuja la pantalla
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

}

void OnTimer(int value)
{

}