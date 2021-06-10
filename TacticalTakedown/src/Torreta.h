#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

class Torreta :
    public Enemigo
{
public:
   // Torreta();
    void mueve(float t);
    void dibuja(); //Funcion de dibujo
    void setVelAng(float vo=45);


    //void persiguePunto(Vector2D Objetivo);//Redefinicion de esta clase dado que no se mueve
};

