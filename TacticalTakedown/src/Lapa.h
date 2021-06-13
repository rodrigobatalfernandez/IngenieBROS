#pragma once
#include "Enemigo.h"

//Enemigo que no dispara, va hacia ti, y cada vez que te choca te quia vida
class Lapa :
    public Enemigo
{
public:
    Lapa();
    void dibuja();
    void dispara(Vector2D& Objetivo, ListaDisparos& lista){/*No dispara*/ }
};

