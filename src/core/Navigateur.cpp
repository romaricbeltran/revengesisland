#include "Navigateur.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>


using namespace std;

Navigateur::Navigateur ()
{
    setPos_x(28);
    setPos_y(8);
    setVie(100);
    n_chance=5;
    score=0;
    niv=1;
}

void Navigateur::DeplacementShoot(Shoot & bn, const Terrain & t)
{
    if(t.estPositionValide(bn.getPos_x()-1, bn.getPos_y()))
    {
        bn.setPos_x(bn.getPos_x()-1);
    }
    else
    {
        bn.setPos_x(getPos_x()-1);
        bn.setPos_y(getPos_y());
    }
}

bool Navigateur::collision(Ennemi& p, const Terrain & t, Shoot& bn)
{
    if(bn.getPos_x()==p.getPos_x()&&bn.getPos_y()==p.getPos_y())
    {
        bn.setPos_x(getPos_x()-1);
        bn.setPos_y(getPos_y());
        int degats=20;
        p.recevoirDegats(degats);
        return true;
    }
    else
    {
        return false;
    }

}

void Navigateur::attaque(Ennemi& p, const Terrain & t, Shoot &bn)
{
    DeplacementShoot(bn, t);

    if(collision(p, t, bn))
    {
        if(!p.estVivant())
        {
            niv=niv+1;
            cout<<"niveau : "<<niv;
            if(niv>4)
            {
                niv=4;
            }
        }
        setScore(getScore()+5);
    }
}

void Navigateur::GestionVie()
{
    while(!estVivant())
    {
        n_chance-=1;
        setNiv(1);
        setScore(0);
        setVie(100);
        cout<<"Votre nombre de vie est de "<<getChance()<<endl;

    }
    if(n_chance==0)
    {
        cout<<"Vous n'avez plus de vie... Vous avez perdu :( "<<endl;
        exit(0);
    }

}

int Navigateur::getChance() const
{
    return n_chance;
}

void Navigateur::setChance(int n)
{
    n_chance=n;
}

void Navigateur::deplacementGauche (const Terrain & t)
{
    if (t.estPositionValide(getPos_x()-1,getPos_y()))
    {
        setPos_x(getPos_x()-1);

    }
}

void Navigateur::deplacementDroite (const Terrain & t)
{
    if (t.estPositionValide(getPos_x()+1,getPos_y())) setPos_x(getPos_x()+1);
}

void Navigateur::deplacementHaut (const Terrain & t)
{
    if (t.estPositionValide(getPos_x(),getPos_y()+1)) setPos_y(getPos_y()+1);
}

void Navigateur::deplacementBas(const Terrain & t)
{
    if (t.estPositionValide(getPos_x(),getPos_y()-1)) setPos_y(getPos_y()-1);
}

int Navigateur::getScore() const
{
    return score;
}

void Navigateur::setScore(int s)
{
    score=s;
}

int Navigateur::getNiv() const
{
    return niv;
}

void Navigateur::setNiv(int ni)
{
    niv=ni;
}

