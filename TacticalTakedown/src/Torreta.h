#pragma once
#include "Enemigo.h"

class Torreta :
    public Enemigo
{
private:
    Vector2D pos_fija;
public:
    void setPos(float ix, float iy);
    Torreta();
    void mueve(float t);
    void dibuja(); //Funcion de dibujo
};

