#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

class Torreta :
    public Enemigo
{
public:
    void mueve(float t);
    void dibuja(); //Funcion de dibujo


    //void persiguePunto(Vector2D Objetivo);//Redefinicion de esta clase dado que no se mueve
};

