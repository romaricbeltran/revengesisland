/**
    \file Navigateur.h
    \brief Fichier d'entete du module Navigateur.
*/
#ifndef _NAVIGATEUR_H
#define _NAVIGATEUR_H
/*!
 * \file Navigateur.h
 * \brief Prototype du module Navigateur
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */
#include "Terrain.h"
#include "Ennemi.h"
#include "Object.h"


class Ennemi;
class Joueur;

/**
\class Navigateur
\brief classe utilisée pour la gestion du Navigateur(joueur).
Navigateur hérite de la classe Object.
\param [in] n_chance Nombre de morts possible du Navigateur avant défaite.
\param [in] score Score du Navigateur
\param [in] niv Niveau du Navigateur
*/
class Navigateur : public Object
{

public:

    /*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Navigateur
         */
    Navigateur ();

    /*-------------------------------------------------------*/
    /** \fn void deplacementGauche (const Terrain & t)
        \brief Deplace le Navigateur d'un cran à gauche
        \param t : de type Terrain
    */

    void deplacementGauche (const Terrain & t);

    /*-------------------------------------------------------*/
    /** \fn void deplacementDroite (const Terrain & t)
        \brief Deplace le Navigateur d'un cran à droite
        \param t : de type Terrain
    */

    void deplacementDroite (const Terrain & t);

    /*-------------------------------------------------------*/
    /** \fn void deplacementHaut (const Terrain & t)
        \brief Deplace le Navigateur d'un cran en haut
        \param t : de type Terrain
    */

    void deplacementHaut (const Terrain & t);

    /*-------------------------------------------------------*/
    /** \fn void deplacementBas (const Terrain & t)
        \brief Deplace le Navigateur d'un cran en bas
        \param t : de type Terrain
    */

    void deplacementBas (const Terrain & t);

    /*-------------------------------------------------------*/
    /** int getChance() const;
    @brief Accesseur de la class Navigateur
    */

    // Accesseur : récupère la variable n_chance
    int getChance() const;

    /*-------------------------------------------------------*/
    /** int getScore() const;
    @brief Accesseur de la class Navigateur
    */

    // Accesseur : récupère la variable score
    int getScore() const;

    /*-------------------------------------------------------*/
    /** int getNiv() const;
    @brief Accesseur de la class Navigateur
    */

    // Accesseur : récupère la variable niv
    int getNiv() const;

    /*-------------------------------------------------------*/
    /** void setChance(int n);
    @brief Mutateur de la class Navigateur
    */

    // Mutateur : modifie la variable n_chance
    void setChance(int n);

    /*-------------------------------------------------------*/
    /** void setScore(int s);
    @brief Mutateur de la class Navigateur
    */

    // Mutateur : modifie la variable score
    void setScore(int s);

    /*-------------------------------------------------------*/
    /** void setNiv(int ni);
    @brief Mutateur de la class Navigateur
    */

    // Mutateur : modifie la variable niv
    void setNiv(int ni);

    /*-------------------------------------------------------*/
    /** \fn void GestionVie()
       \brief Enlève une chance si le navigateur tombe à 0 point de vie et "recommence la partie", si le navigateur n'a plus de vie on sort du programme
    */
    void GestionVie();

    /*-------------------------------------------------------*/
    /** \fn void attaque(Ennemi &p, const Terrain & t, Shoot &b)
        \brief Le navigateur tire et augmente le score de 5 si le shoot touche l'ennemi, et le niveau de 1 si l'ennemi meurt
        \param p : référence sur Ennemi
        \param t : de type Terrain
        \param b : de type Shoot
    */
    void attaque(Ennemi &p, const Terrain & t, Shoot &b);

    /*-------------------------------------------------------*/
    /** \fn bool collision(Ennemi & p, Terrain & t)
        \brief Renvoie true si le shoot du navigateur rencontre la position de l'ennemi et inflige des dégats à ce dernier, sinon renvoie false
        \param p : référence sur Ennemi
        \param t : de type Terrain
        \param b : de type Shoot
    */
    bool collision(Ennemi &p, const Terrain & t, Shoot  &b);

    /*-------------------------------------------------------*/
    /** \fn void DeplacementShoot(Shoot & bn, const Terrain & t)
        \brief Déplace le shoot du Navigateur d'un cran à gauche si la position qui suit celui-ci est libre
        \param t : de type Terrain
        \param bn : de type Shoot
    */
    void DeplacementShoot(Shoot & bn, const Terrain & t);

private :
    int n_chance;
    int score;
    int niv;

};


#endif
