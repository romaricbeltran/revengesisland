
/**
    \file Objet.h
    \brief Fichier d'entete du module Object.
*/
#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>
#include <math.h>
#include <unistd.h>
#include "Animation.h"
const int dimx=1260;
const int dimy=540;
class Objet
{
public:
    float x,y,dx,dy,R,angle;
    bool vie;
    std::string nom;
    Animation anim;

    Objet()
    {
        vie=1;
    }
    virtual ~Objet() {}
    void parametres(Animation &a, float X, float Y, float Angle=0, int radius=1)
    {
        x=X;
        y=Y;
        anim=a;
        angle=Angle;
        R=radius;
    }

    virtual void update()
    {


    };

    void draw(sf::RenderWindow &win)
    {
        anim.sp.setPosition(x,y);
        anim.sp.setRotation(angle+90);
        win.draw(anim.sp);
    }
};

class ennemi: public Objet
{
public:

    ennemi()
    {
        dx=rand()%4-6;
        dy=0;
        nom="boss";
    }

    void update()
    {
        x+=dx;
        y+=dy;
        if(x>dimx+2400) x=dx;
        if(x<1300) x=dimx+2400;
        if(y>dimy) y=dy;
        if(y<0) y=dimy;
    }

};

class hache : public Objet
{
public :
    hache()
    {
        nom="hache";
    }

    void update()
    {
        dx=cos(angle*(3.14 / 180))*6;
        dy=sin(angle*(3.14 / 180))*6;
        x+=dx;
        y+=dy;
        // if(x>dimx ||x<0||y>dimy||y<0) vie=0;
    }

};

class Boss: public Objet
{
public:

    Boss()
    {
        dx=rand()%4-6;
        dy=0;
        nom="boss";
    }

    void update()
    {
        x+=dx;
        y+=dy;
        if(x>dimx+1400) x=dx;
        if(x<1300) x=dimx+1400;
        if(y>dimy) y=dy;
        if(y<0) y=dimy;
    }

};

#endif // OBJET_H_INCLUDED
