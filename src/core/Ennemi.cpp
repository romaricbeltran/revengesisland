#include "Ennemi.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "Shoot.h"

using namespace std;

Ennemi::Ennemi()
{
    setPos_x(10);
    setPos_y(10);
}


void Ennemi::DeplaceXAuto (const Terrain & t)
{
    string d [7] = {"0", "0", "0", "haut", "bas", "gauche", "droite"};
    int temp = getDir();
        switch (temp)
        {
        case 3:
            if (t.estPositionValide(getPos_x(),getPos_y()+2))
            {
                setPos_y(getPos_y()+1);
            }
            break;
        case 4 :
            if (t.estPositionValide(getPos_x(),getPos_y()+1))
            {
                setPos_y(getPos_y()-1);
            }
            break;
        case 5 :
            if (t.estPositionValide(getPos_x()-1,getPos_y()))
            {
                setPos_x(getPos_x()-1);
            }
            break;
        case 6 :
            if (t.estPositionValide(getPos_x()+1,getPos_y()))
            {
                setPos_x(getPos_x()+1);

            }
            break;
    default :
            break;
        }

    setDir(rand()%7); // augmenter pour ralentir l'ennemi (min:7 si l'on veut qu'il se déplace dans tous les sens)
}

void Ennemi::TirAuto(Navigateur & n, const Terrain & t, Shoot & be)
{
    if(t.estPositionValide(be.getPos_x()+1, be.getPos_y()))
    {
            be.setPos_x(be.getPos_x()+1);
    }
    else
    {
        be.setPos_x(getPos_x()-1);
        be.setPos_y(getPos_y());
    }

    if(be.getPos_x()==n.getPos_x()&&be.getPos_y()==n.getPos_y())
    {
        be.setPos_x(getPos_x()-1);
        be.setPos_y(getPos_y());
        int degats=20;
        n.recevoirDegats(degats);
        n.GestionVie();
    }

}
