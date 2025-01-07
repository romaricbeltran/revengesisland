#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objet.h"


class Nav
{
    public:
    Nav();
    ~Nav();
    void CameraPerso();
    void FpsPerso();

    //
    bool vie;
    std::string nom;

    //Perso
    sf::Sprite sprite_perso;
    sf::Texture perso;
    //Allié
    bool aff_allie1=false;
    bool can_shoot1=false;
    sf::Sprite sprite_allie1;
    sf::Texture allie;

    //Direction personnage
    sf::View view;
    enum Dir {Up, Right, Down, Left};
    sf::Vector2i anim=sf::Vector2i(1,Down);
    sf::Vector2f position=sf::Vector2f(400,300);
    bool updateFPS = true;
    sf::Clock time;
    //Direction allie
    sf::Vector2i animA=sf::Vector2i(1,Down);
    sf::Vector2f positionA=sf::Vector2f(400,300);
    bool updateFPSA = true;
};
