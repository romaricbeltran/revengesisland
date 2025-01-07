#include "Object.h"

using namespace std;

Object::Object()
{

}
Object::Object(int x, int y)
{
    pos_x=x;
    pos_y=y;
    p_vie=50;
}

int Object::getPos_x () const
{
    return pos_x;
}

int Object::getPos_y () const
{
    return pos_y;
}

int Object::getDir() const
{
    return dir;
}

int Object::getVie() const
{
    return p_vie;
}

void Object::setPos_x(int x)
{
    pos_x=x;
}

void Object::setPos_y(int y)
{
    pos_y=y;
}

void Object::setDir(int di)
{
    dir=di;
}

void Object::setVie(int v)
{
    p_vie=v;
}

void Object::setPosition(int x, int y)
{
    pos_x=x;
    pos_y=y;
}

void Object::recevoirDegats(int nbDegats)
{
    p_vie-=nbDegats;
    if(p_vie<=0)
    {
        p_vie=0;
    }
}

bool Object::estVivant()
{
    if (p_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
