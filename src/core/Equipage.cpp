#include "Equipage.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

Equipage::Equipage()
{
    Ennemi();
    setPos_x(32);
    setPos_y(8);

}

void Equipage::TirAllie(Ennemi & n, const Terrain& t, Shoot &  balle)
{
    if(t.estPositionValide(balle.getPos_x()-1, balle.getPos_y()))
    {
        balle.setPos_x((balle.getPos_x()-(n.getPos_x())));
        balle.setPos_y((n.getPos_y()));

    }
    else
    {
        balle.setPos_x(getPos_x()-1);
        balle.setPos_y(getPos_y());
    }

    if(balle.getPos_x()==n.getPos_x()&&balle.getPos_y()==n.getPos_y())
    {
        balle.setPos_x(getPos_x()-1);
        balle.setPos_y(getPos_y());
        int degats=5;
        n.recevoirDegats(degats);

    }
}
