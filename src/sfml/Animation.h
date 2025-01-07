/**
    \file Animation.h
    \brief Fichier d'entete du module Animation.
*/
#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <SFML/Graphics.hpp>

/**
\class Animation
\brief classe utilisée pour la gestion des Objets.
\param [in] Frame : flottant définit la position en abscisse de l'objet
\param [in] speed : flottant définit la position en ordonnée de l'objet
\param [in] frames : Vecteur de type IntRect contenant les différence frames de l'animation
*/
class Animation
{
public :

    float Frame, speed;

    sf::Sprite sp;
    std::vector<sf::IntRect> frames;

/*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Animation
         */
    Animation();

    /*-------------------------------------------------------*/
    /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur par copie de la classe Animation
     *
     *  \param t : Référence sur texture
     *  \param x : positions selon les x
     * 	\param y : positions selon les y
     *	\param w : largeur de l'image
     *	\param h : hauteur de l'image
     *	\param Count : nombre d'image du sprite
     *  \param Speed : vitesse d'affichage
     */

    Animation(sf::Texture &t, int x, int y, int w, int h, int Count, float Speed);
    /*-------------------------------------------------------*/
    /** void update();
    @brief update de la class animation
    */

    // Permet de mettre a jour la frame
    void update();
    /*-------------------------------------------------------*/
    /** bool isEnd();
    @brief bool qui renvoit si true ou false en fonction de si l'animation est finie ou pas
    */

    // Permet de savoir si elle est finie
    bool isEnd();

};

#endif // ANIMATION_H_INCLUDED
