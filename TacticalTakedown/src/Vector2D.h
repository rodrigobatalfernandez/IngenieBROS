#pragma once

class Vector2D {
public:	//ATRIBUTOS 
	float x;
	float y;
public:	//METODOS 
	Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)constructor (emplea valores por defecto)
	float modulo();								// (2) modulo del vector (con convbersión forzosa a float)
	float argumento();							// (3) argumento del vector (empleando atan2)
	Vector2D unitario();						// (4) devuelve un vector unitario 
	Vector2D operator - (Vector2D);				// (5) resta de vectores (con sobrecarga de operador)
	Vector2D operator + (Vector2D);				// (6) suma de vectores (con sobrecarga de operador)
	float operator * (Vector2D);				// (7) producto escalar (con sobrecarga múltiple de operador)
	Vector2D operator * (float);				// (8) producto por un escalar (con sobrecarga múltiple de operador)
	static bool onSegment(Vector2D p, Vector2D q, Vector2D r);						// (9) Detectar si tres puntos son colineales
	static float orientation(Vector2D p, Vector2D q, Vector2D r);					// (10) Detectar el vector de giro de 3 puntos
	static bool Interseccion(Vector2D p1, Vector2D q1, Vector2D p2, Vector2D q2);	// (11) Detectar la interaccion de dos segmentos
};