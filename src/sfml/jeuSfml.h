#ifndef _JEUSFML_H
#define _JEUSFML_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include "Animation.h"
#include "Objet.h"

#include "../core/Jeu.h"
#include "Nav.h"

class Jeu;

class sfmlJeu
{
public:

    Jeu jeu;

    sf::RenderWindow window;
    sf::Font font;
    sf::Music blood;
    sf::Music bande;
    sf::Text text;

    Nav n;


    //Sprites et textures pour le terrain
    sf::Texture tSable;
    sf::Texture tEau;
    sf::Texture tPavet;
    sf::Texture boat;
    sf::Sprite spBoat;
    sf::Sprite spEau;
    sf::Texture rock;
    sf::Sprite spRock;
    sf::Texture wreckage;
    sf::Sprite spWreckage ;
    sf::Texture sang;
    sf::Texture axe;
    sf::Texture ennemy;
    sf::Texture boss;
    sf::Texture tree;
    sf::Texture grass;
    sf::Sprite sGrass;
    sf::Texture dalle;
    sf::Texture carrelage;
    sf::Texture stoneHouse;
    sf::Sprite spStoneHouse;
    sf::Texture hachette;
    sf::Sprite spHachette;
    sf::Texture feu;

    //Variables pour l'affichage du personnage
    float angle_tir;
    float Frame=0;
    float animSpeed=0.8;
    int frameCount=20;

    //Liste d'elements de type objet
    std::list<Objet*> en;

    int score=0;

    //Vague d'ennemis
    bool stop;
    bool vagueBoss;

public:

    sfmlJeu();
    ~sfmlJeu();
    void SfmlBoucle();
    void SfmlAff();
    void AfficheTerrain();
};


#endif
