#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu)
{
    const Terrain& ter = jeu.getConstTerrain();
    const Navigateur& nav = jeu.getConstNavigateur();
    const Ennemi& en = jeu.getConstEnnemi();
    const Equipage& eq = jeu.getConstEquipage();
    const Shoot& e = jeu.getConstshootEn();
    const Shoot& n = jeu.getConstshootNav();
    const Shoot& a = jeu.getConstshootEq();

    win.clear();

    // Affichage des murs
    for(int x=0; x<ter.getDimX(); ++x)
        for(int y=0; y<ter.getDimY(); ++y)
            win.print(x,y,ter.getXY(x,y));

    // Affichage du navigateur
    win.print(nav.getPos_x(),nav.getPos_y(),'P');
    // Affichage de l'ennemi
    win.print(en.getPos_x(),en.getPos_y(),'E');
    //win.print(en1.getPos_x(),en1.getPos_y(),'P');
    //Affichage de l'equipage
    win.print(eq.getPos_x(),eq.getPos_y(),'A');
    //Affichage hache
    win.print(e.getPos_x(), e.getPos_y(), '<');

    win.print(n.getPos_x(), n.getPos_y(), '>');

    win.print(n.getPos_x(), n.getPos_y(), '>');

    win.print(a.getPos_x(), a.getPos_y(), 'X');

    win.draw();
}
void txtBoucle (Jeu & jeu)
{
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

    bool ok = true;
    int c;

    do
    {
        txtAff(win,jeu);

#ifdef _WIN32
        Sleep(100);
#else
        usleep(110000); //vitesse classique 99999
#endif // WIN32

        jeu.actionsAutomatiques();

        c = win.getCh();
        switch (c)
        {
        case 't':
            jeu.actionClavier('t');
            break;
        case 'g':
            jeu.actionClavier('g');
            break;
        case 'h':
            jeu.actionClavier('h');
            break;
        case 'f':
            jeu.actionClavier('f');
            break;
        case 'a' :
            jeu.actionClavier('a');
            break;
        case 'q':
            ok = false;
            break;
        }

    }
    while (ok);

}
