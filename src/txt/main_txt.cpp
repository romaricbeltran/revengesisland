#include "winTxt.h"
#include "txtJeu.h"
#include "../core/Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

int main ( int argc, char** argv )
{
    termClear();
    Menu m;
    int choice;
    Jeu jeu;
    choice=m.menu();

    do
    {

        switch (choice)
        {
        case '1':

            txtBoucle(jeu);
            choice= m.menu();
            break;
        case '2':
            termClear();
            cout<<"\nT : Avancer\nG : Reculer\nF : Gauche\nH : Droite"<<endl;
            cout<<"\nPour mettre le jeu en pause cliquez n'importe où dans la fenêtre.\nEspace pour reprendre le jeu.\nDans le jeu : taper q pour quitter\n"<<endl;
            choice=m.menu();
            break;
        case '3':
            exit(0);

        }

    }
    while (choice!='6');

    termClear();
    return 0;
}
