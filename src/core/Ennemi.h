/**
    \file Ennemi.h
    \brief Fichier d'entete du module Ennemi.
*/
#ifndef _Ennemi_H
#define _Ennemi_H
/*!
 * \file Ennemi.h
 * \brief Prototype du module Ennemi
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */
#include <iostream>
#include "Terrain.h"
#include "Shoot.h"
#include "Navigateur.h"
#include "Object.h"

class Navigateur;
/**
\class Ennemi
\brief classe utilisée pour la gestion de l'Ennemi.
Ennemi hérite de la classe Object.
*/
class Ennemi : public Object
{

public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Ennemi
         */
    Ennemi();

    /*-------------------------------------------------------*/
    /** \fn void DeplaceXAuto (const Terrain & t)
        \brief Deplace l'ennemi aléatoirement d'un cran en haut à gauche à droite ou à gauche
        \param t : de type Terrain
    */
    void DeplaceXAuto (const Terrain & t);

    /*-------------------------------------------------------*/
    /** \fn void TirAuto(Navigateur & n, const Terrain & t, Shoot & be)
        \brief Deplace le shoot de l'Ennemi sur la droite si il n'y pas d'obstacle et si les coordonnées du shoot et du Navigateur se rencontre, applique la gestion des points de vie au Navigateur
        \param n : référence sur Navigateur
        \param t : de type Terrain
        \param be : de type Shoot
    */
    void TirAuto(Navigateur & n, const Terrain & t, Shoot & be);

};

#endif
