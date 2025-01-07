#define SDL_MAIN_HANDLED
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../core/Jeu.h"

//! \brief Pour gérer une image avec SDL2
class Image
{

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
};



/**
    La classe gérant le jeu avec un affichage SDL
*/
class sdlJeu
{

private :

    Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;
    TTF_Font *font;

    SDL_Surface *pvSurface;
    SDL_Surface *ScoreSurface;
    SDL_Surface *ChanceSurface;
    SDL_Surface *VictoireSurface;
    SDL_Surface *NiveauSurface;

    SDL_Rect chanceRect;
    SDL_Rect pvRect;
    SDL_Rect ScoreRect;
    SDL_Rect VictoireRect;
    SDL_Rect NiveauRect;

    SDL_Texture *Chance;
    SDL_Texture *Victoire;
    SDL_Texture *Points_vie;
    SDL_Texture *Score;
    SDL_Texture *Niveau;

    Image im_naviateur;
    Image im_mur;
    Image im_ennemi;
    Image im_equipage;
    Image im_projectil3;
    Image im_projectil1;
    Image im_projectil2;
    Image im_bois;
    Image im_eau;
    Image im_sable;
    Image im_vague;
    Image im_chance;
    Image im_feu;
    //Terrain 2
    Image im_arbre;
    Image im_herbe;
    //Terrain3
    Image im_pierre;
    Image im_dalle;
    Image im_rempart;
    //TerrainFinal
    Image im_tapis;
    Image im_marchetapis;
    Image im_carrelage;
    Image im_marchecarrelagehaut;
    Image im_marchecarrelagebas;
    Image im_marchecarrelagecote;
    Image im_anglecarrelagebas;
    Image im_anglecarrelagehaut;
    Image im_plateforme;
public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlMenu();
    void sdlBoucle ();
    void sdlDrawTer1();
    void sdlDrawTer2();
    void sdlDrawTer3();
    void sdlDrawTer4();
    void sdlAff ();
    void animation(SDL_Rect * clip);


};

#endif
