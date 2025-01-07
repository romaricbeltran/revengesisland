/**
    \file Jeu.h
    \brief Fichier d'entete du module Jeu.
*/
#ifndef _JEU_H
#define _JEU_H

/*!
 * \file Jeu.h
 * \brief Prototype du module Jeu
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */
#include "Navigateur.h"
#include "Terrain.h"
#include "Ennemi.h"
#include "Equipage.h"
#include "Shoot.h"
#include "../txt/winTxt.h"

/**
\class Jeu
\param [in] nav Navigateur
\param [in] en Ennemi
\param [in] eq Equipage
\param [in] shootNav Shoot du Navigateur
\param [in] shootEn Shoot de l'Ennemi
\param [in] shootEq Shoot de l'Equipage
\param [in] ter Terrain
*/

class Jeu
{

public :

    /*!
             *  \brief Constructeur
             *
             *  Constructeur par défaut de la classe Jeu
             */
    Jeu ();

    /*-------------------------------------------------------*/

    /** Terrain& getConstTerrain () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable ter
const Terrain& getConstTerrain () const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstNavigateur () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable nav
const Navigateur& getConstNavigateur () const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstEnnemi () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable en
const Ennemi& getConstEnnemi () const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstEquipage () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable eq
const Equipage& getConstEquipage() const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstshootNav () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable shootNav
const Shoot& getConstshootNav() const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstshootEn () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable shootEn
const Shoot& getConstshootEn() const;

    /*-------------------------------------------------------*/

    /** Terrain& getConstshootEq () const;
    @brief Accesseur de la class Jeu
*/

   // Accesseur : récupère la variable shootEq
const Shoot& getConstshootEq() const;

    /*-------------------------------------------------------*/

    /** \fn void actionsAutomatiques ()
       \brief Enclenche un deplacement aléatoire de l'ennemi, et un shoot de l'ennemi, du navigateur et de l'équipage
    */
    void actionsAutomatiques ();

    /*-------------------------------------------------------*/

    /** \fn void actionClavier(const char touche)
        \brief Attribue des touches du claviers au mouvement du navigateur
        \param touche : un caractère
    */
    void actionClavier(const char touche);

    /*-------------------------------------------------------*/

    /** \fn void changerNiveau()
        \brief Enclenche un changement de terrain lorsque le navigateur gagne un niveau
    */
    void changerNiveau();

private :

    Navigateur nav;
    Ennemi en;
    Equipage eq;
    Shoot shootNav;
    Shoot shootEn;
    Shoot shootEq;
    Terrain ter;

};

#endif
