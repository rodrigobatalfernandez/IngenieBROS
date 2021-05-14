//#include"ListaParedes.h"
//#include "Interaccion.h"
//
//ListaParedes::ListaParedes()
//{
//	numero = 0;
//	for (int i = 0; i < MAX_PAREDES; i++)
//		lista[i] = 0;
//}
//
//bool ListaParedes::agregar(Pared* p)
//{
//	bool error = false;
//	for (int i = 0; i < numero; i++)
//	{
//		if (lista[i] == p)
//			error = true;
//	}
//	if (error == false && numero < MAX_PAREDES)
//		lista[numero++] = p; // último puesto sin rellenar
//	else
//		return false; // capacidad máxima alcanzada
//	return true;
//}
//
//void ListaParedes::dibuja()
//{
//	for (int i = 0; i < numero; i++)
//		lista[i]->dibuja();
//}
//
//void ListaParedes::colision(Disparo d)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::colision(d,*(lista[i]));
//}
//
//void ListaParedes::colision(Jugador j)
//{
//	for (int i = 0; i < numero; i++)
//		Interaccion::colision(j, *(lista[i]));
//}
//
//void ListaParedes::destruirContenido()
//{
//	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
//		delete lista[i];
//	numero = 0; // inicializa lista
//}