#include "Nav.h"

Nav::Nav()
{
        perso.loadFromFile("./data/perso.png");
    allie.loadFromFile("./data/allie.png");
}

void Nav::CameraPerso()
{
    sprite_perso.setTextureRect(sf::IntRect(anim.x*72, anim.y*96, 72, 96));
    sprite_allie1.setTextureRect(sf::IntRect(anim.x*72, anim.y*96, 72, 96));

    view.reset(sf::FloatRect(0,0,1260,540));

    position.x=sprite_perso.getPosition().x+36-(630);
    position.y=sprite_perso.getPosition().y+48-(270);

    positionA.x=sprite_allie1.getPosition().x+36-(630);
    positionA.y=sprite_allie1.getPosition().y+48-(270);


    if(position.x<0)
        position.x=0;
    if(position.y<0)
        position.y=0;
    if(position.x>dimx+2500)
        position.x=dimx+2500;

    if(positionA.x<0)
        positionA.x=0;
    if(positionA.y<0)
        positionA.y=0;

    view.reset(sf::FloatRect(position.x, position.y,1260,540));
    view.zoom(1);

}

void Nav::FpsPerso()
{
    if(sprite_perso.getPosition().x<=300)
    {
        sprite_perso.setPosition(sf::Vector2f(300,sprite_perso.getPosition().y));
    }
    if(sprite_perso.getPosition().y<=0)
    {
        sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x,0));
    }
    if(sprite_perso.getPosition().x>=dimx+2500)
    {
        sprite_perso.setPosition(sf::Vector2f(dimx+2500,sprite_perso.getPosition().y));
    }
    if(sprite_perso.getPosition().y>=dimy-430)
    {
        sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x,dimy-430));
    }

    if(sprite_allie1.getPosition().x<=180)
    {
        sprite_allie1.setPosition(sf::Vector2f(180,sprite_allie1.getPosition().y));
    }
    if(sprite_allie1.getPosition().y<=0)
    {
        sprite_allie1.setPosition(sf::Vector2f(sprite_allie1.getPosition().x,0));
    }
    if(sprite_allie1.getPosition().x>=dimx+2500)
    {
        sprite_allie1.setPosition(sf::Vector2f(dimx+2500,sprite_allie1.getPosition().y));
    }
    if(sprite_allie1.getPosition().y>=dimy-430)
    {
        sprite_allie1.setPosition(sf::Vector2f(sprite_allie1.getPosition().x,dimy-430));
    }

    if(updateFPS==true)
    {
        if(time.getElapsedTime().asMilliseconds()>=50)
        {
            anim.x--;
            if(anim.x*72>=perso.getSize().x)
            {
                anim.x=2;
            }
            time.restart();
        }
    }
}

Nav::~Nav()
{

}
