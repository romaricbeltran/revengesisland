/**
    \file Object.h
    \brief Fichier d'entete du module Object.
*/
#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
/*!
 * \file Object.h
 * \brief Prototype du module Object
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */

/**
\class Object
\brief classe utilisée pour la gestion des Objets.
\param [in] pos_x : entier définit la position en abscisse de l'objet
\param [in] pos_y : entier définit la position en ordonnée de l'objet
\param [in] dir : entier définit la direction de déplacement futur de l'objet
\param [in] p_vie : entier définit les points de vie de l'objet
*/
class Object
{
public :
/*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Object
         */
    Object();

    /*-------------------------------------------------------*/
    /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur par copie de la classe Object
     *
     *  \param x : entier correspondant à pos_x
     *  \param y : entier correspondant à pos_y
     */
    Object(int x, int y);

    //Accesseurs

    /*-------------------------------------------------------*/
    /** int getPos_x() const;
    @brief Accesseur de la class Object
    */

    // Accesseur : récupère la variable pos_x
    int getPos_x () const;

    /*-------------------------------------------------------*/
    /** int getPos_y() const;
    @brief Accesseur de la class Object
    */

    // Accesseur : récupère la variable pos_y
    int getPos_y () const;

    /*-------------------------------------------------------*/
    /** int getDir() const;
    @brief Accesseur de la class Object
    */

    // Accesseur : récupère la variable dir
    int getDir () const;

    /*-------------------------------------------------------*/
    /** int getVie() const;
    @brief Accesseur de la class Object
    */

    // Accesseur : récupère la variable p_vie
    int getVie() const;

    //Mutateurs

    /*-------------------------------------------------------*/
    /** void setPos_x(int x);
    @brief Mutateur de la class Object
    */

    // Mutateur : modifie la variable pos_x
    void setPos_x(int x);

    /*-------------------------------------------------------*/
    /** void setPos_y(int x);
    @brief Mutateur de la class Object
    */

    // Mutateur : modifie la variable pos_y
    void setPos_y(int y);

    /*-------------------------------------------------------*/
    /** void setDir(int di);
    @brief Mutateur de la class Object
    */

    // Mutateur : modifie la variable dir
    void setDir (int di);

    /*-------------------------------------------------------*/
    /** void setVie(int v);
    @brief Mutateur de la class Object
    */

    // Mutateur : modifie la variable p_vie
    void setVie(int v);

    /*-------------------------------------------------------*/
    /** void setPosition(int x, int y);
    @brief Mutateur de la class Object
    */

    // Mutateur : modifie les variables pos_x et pos_y
    void setPosition(int x, int y);

    /*-------------------------------------------------------*/
    /** \fn void recevoirDegats(int nbDegats)
       \brief Enlève des points de vie à l'Objet
       \param nbDegats : entier définit le nombre de points de vie à enlever
    */
    void recevoirDegats(int nbDegats);

    /*-------------------------------------------------------*/
    /** \fn bool estVivant()
       \brief Renvoit true si l'Objet à encore des points de vie et false sinon
    */
    bool estVivant();

private:

    int pos_x,pos_y;
    int dir;
    int p_vie;
};


#endif // OBJECT_H_INCLUDED
