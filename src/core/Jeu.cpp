#include "Jeu.h"
#include <iostream>
#include <string>
#include <assert.h>
#define FIREBALLS_MAX 3
using namespace std;
Jeu::Jeu () :  nav(), en(), eq(), shootNav(), shootEn(), shootEq(),  ter()
{

}

const Terrain& Jeu::getConstTerrain () const
{
    return ter;
}

const Navigateur& Jeu::getConstNavigateur () const
{
    return nav;
}

const Equipage& Jeu::getConstEquipage () const
{
    return eq;
}

const Ennemi& Jeu::getConstEnnemi () const
{
    return en;
}


const Shoot& Jeu::getConstshootNav() const
{
    return shootNav;
}

const Shoot& Jeu::getConstshootEn() const
{
    return shootEn;
}

const Shoot& Jeu::getConstshootEq() const
{
    return shootEq;
}

void Jeu::actionsAutomatiques ()
{
    en.TirAuto(nav, ter, shootNav);
    nav.attaque(en, ter, shootEn);
    eq.TirAllie(en, ter, shootEq);
    en.DeplaceXAuto(ter);
}

void Jeu::actionClavier (const char touche)
{
    switch(touche)
    {
    case 'f' :
        nav.deplacementGauche(ter);
        break;
    case 'h' :
        nav.deplacementDroite(ter);
        break;
    case 'g' :
        nav.deplacementHaut(ter);
        break;
    case 't' :
        nav.deplacementBas(ter);
        break;

    }
}

void Jeu::changerNiveau()
{
    if(nav.getNiv()==1)
    {
        ter.ChangeMap(1);
    }
    else if(nav.getNiv()==2)
    {
        ter.ChangeMap(2);
    }
    else if(nav.getNiv()==3)
    {
        ter.ChangeMap(3);
    }
    else if(nav.getNiv()==4)
    {
        ter.ChangeMap(4);
    }

}
