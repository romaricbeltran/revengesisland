/**
    \file Menu.h
    \brief Fichier d'entete du module Menu.
*/
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
/*!
 * \file Menu.h
 * \brief Prototype du module Menu
 * \author DJEBARNI-BELTRAN
 * \version 1.0
 */

 /**
\class Menu
\brief classe utilisée pour la gestion du Menu.
\param [in] choice : entier de selection
*/
class Menu
{

public :
    /*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Menu
         */
    int menu();

private :
    int choice;
};

#endif // MENU_H_INCLUDED
