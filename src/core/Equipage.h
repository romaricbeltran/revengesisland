/**
    \file Equipage.h
    \brief Fichier d'entete du module Equipage.
*/
#ifndef EQUIAGE_H_INCLUDED
#define EQUIAGE_H_INCLUDED
/*!
 * \file Equipage.h
 * \brief Prototype du module Equipage
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */
#include "Terrain.h"
#include "Object.h"
#include "Ennemi.h"

/**
\class Equipage
\brief classe utilisée pour la gestion de l'Equipage.
Equipage hérite de la classe Object.
*/
class Equipage : public Object
{

public:

    /*-------------------------------------------------------*/
    /*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Equipage
         */
    Equipage();

    /*-------------------------------------------------------*/
    /** \fn void TirAllie(Ennemi & n, const Terrain &t, Shoot & balle)
        \brief Deplace le shoot de l'Equipage en direction de la dernière position de l'Ennemi et applique la collision sur celui-ci si elle a lieu
        \param n : référence sur Ennemi
        \param t : de type Terrain
        \param balle : de type Shoot
    */
    void TirAllie(Ennemi & n, const Terrain &t, Shoot & balle);

};


#endif // EQUIAGE_H_INCLUDED
