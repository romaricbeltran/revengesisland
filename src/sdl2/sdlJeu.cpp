#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

const int TAILLE_SPRITE = 30;

float temps ()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image ()
{
    surface = NULL;
    texture = NULL;
    has_changed = false;
}


void Image::loadFromFile (const char* filename, SDL_Renderer * renderer)
{
    surface = IMG_Load(filename);
    if (surface == NULL)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL)
        {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL)
    {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL)
    {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;



    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed)
    {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : jeu()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    font=TTF_OpenFont("./data/asman.TTF", 35);
    TTF_SetFontStyle(font, TTF_STYLE_BOLD);

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int dimx, dimy;
    dimx = jeu.getConstTerrain().getDimX();
    dimy = jeu.getConstTerrain().getDimY();
    dimx = dimx * TAILLE_SPRITE;
    dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Revenge's Island", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy+50, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    im_naviateur.loadFromFile("./data/nav.png",renderer);
    im_mur.loadFromFile("./data/mur.png",renderer);
    im_ennemi.loadFromFile("./data/ennemi.png",renderer);
    im_projectil1.loadFromFile("./data/hache.png",renderer);
    im_projectil2.loadFromFile("./data/lance.png",renderer);
    im_bois.loadFromFile("./data/bois.png", renderer);
    im_eau.loadFromFile("./data/eau.png", renderer);
    im_sable.loadFromFile("./data/sable.png",renderer);
    im_vague.loadFromFile("./data/vague.png",renderer);
    im_equipage.loadFromFile("./data/equipage.png", renderer);
    im_projectil3.loadFromFile("./data/couteau.png", renderer);
    im_chance.loadFromFile("./data/coeur.png", renderer);
    im_feu.loadFromFile("./data/feu.gif", renderer);
    //Terrain2
    im_arbre.loadFromFile("./data/arbre.png", renderer);
    im_herbe.loadFromFile("./data/herbe.png", renderer);
    //Terrain3
    im_pierre.loadFromFile("./data/pierre.png", renderer);
    im_dalle.loadFromFile("./data/dalle.png", renderer);
    im_rempart.loadFromFile("./data/rempart.png", renderer);
    //TerrainFinal
    im_tapis.loadFromFile("./data/tapis.png", renderer);
    im_marchetapis.loadFromFile("./data/marchetapis.png", renderer);
    im_carrelage.loadFromFile("./data/carrelage.png", renderer);
    im_marchecarrelagehaut.loadFromFile("./data/marchecarrelagehaut.png", renderer);
    im_marchecarrelagebas.loadFromFile("./data/marchecarrelagebas.png", renderer);
    im_marchecarrelagecote.loadFromFile("./data/marchecarrelagecote.png", renderer);
    im_anglecarrelagebas.loadFromFile("./data/anglecarrelagebas.png", renderer);
    im_anglecarrelagehaut.loadFromFile("./data/anglecarrelagehaut.png", renderer);
    im_plateforme.loadFromFile("./data/plateforme.png", renderer);
}

sdlJeu::~sdlJeu ()
{
    TTF_Quit();
    SDL_DestroyTexture(Points_vie);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void sdlJeu::sdlMenu()
{
    SDL_Texture *img = NULL;
    int w, h; // texture width & height


    img = IMG_LoadTexture(renderer, "./data/Menu.png");
    SDL_QueryTexture(img, NULL, NULL, &w, &h);

    SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = w; texr.h = h;

    // main loop
    while (1) {

        SDL_Event e;
        if ( SDL_PollEvent(&e) )
        {
             if (e.type == SDL_QUIT) exit(0);
             else
            if (e.key.keysym.sym == SDLK_KP_1)
                break;
            else if (e.key.keysym.sym == SDLK_KP_2)
                break;
            else if (e.key.keysym.sym == SDLK_KP_3)
                exit(0);
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, img, NULL, &texr);

        SDL_RenderPresent(renderer);
    }
}

void sdlJeu::sdlDrawTer1()
{
    int x,y;
    const Terrain& ter = jeu.getConstTerrain();

    for (x=0; x<ter.getDimX(); ++x)
        for (y=0; y<ter.getDimY(); ++y)
            if (ter.getXY(x,y)=='@')
                im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if(ter.getXY(x,y)=='S')
                im_sable.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*5,TAILLE_SPRITE*5);
            else if (ter.getXY(x,y)=='B')
                im_bois.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if (ter.getXY(x,y)=='1')
                im_eau.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if(ter.getXY(x,y)=='V')
                im_vague.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
            else if(ter.getXY(x,y)=='F')
                im_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

}

void sdlJeu::sdlDrawTer2()
{
    int x,y;
    const Terrain& ter = jeu.getConstTerrain();

    for (x=0; x<ter.getDimX(); ++x)
        for (y=0; y<ter.getDimY(); ++y)
            if (ter.getXY(x,y)=='@')
                im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if(ter.getXY(x,y)=='H')
                im_herbe.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*5,TAILLE_SPRITE*5);
            else if (ter.getXY(x,y)=='A')
                im_arbre.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if(ter.getXY(x,y)=='F')
                im_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
}

void sdlJeu::sdlDrawTer3()
{
    int x,y;
    const Terrain& ter = jeu.getConstTerrain();

    for (x=0; x<ter.getDimX(); ++x)
        for (y=0; y<ter.getDimY(); ++y)
            if (ter.getXY(x,y)=='@')
                im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if(ter.getXY(x,y)=='P')
                im_pierre.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*5,TAILLE_SPRITE*5);
            else if (ter.getXY(x,y)=='D')
                im_dalle.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if (ter.getXY(x,y)=='R')
                im_rempart.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if(ter.getXY(x,y)=='F')
                im_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
}

void sdlJeu::sdlDrawTer4()
{
    int x,y;
    const Terrain& ter = jeu.getConstTerrain();

    for (x=0; x<ter.getDimX(); ++x)
        for (y=0; y<ter.getDimY(); ++y)
            if (ter.getXY(x,y)=='@')
                im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if(ter.getXY(x,y)=='T')
                im_tapis.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (ter.getXY(x,y)=='t')
                im_marchetapis.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (ter.getXY(x,y)=='c')
                im_carrelage.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (ter.getXY(x,y)=='d')
                im_marchecarrelagehaut.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (ter.getXY(x,y)=='m')
                im_marchecarrelagebas.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1,TAILLE_SPRITE*1);
            else if (ter.getXY(x,y)=='w')
                im_marchecarrelagecote.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1,TAILLE_SPRITE*1);
            else if (ter.getXY(x,y)=='<')
                im_anglecarrelagebas.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1,TAILLE_SPRITE*1);
            else if (ter.getXY(x,y)=='>')
                im_anglecarrelagehaut.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1,TAILLE_SPRITE*1);
            else if (ter.getXY(x,y)=='p')
                im_plateforme.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);
            else if(ter.getXY(x,y)=='F')
                im_feu.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
}

void sdlJeu::sdlAff ()
{
    //Remplir l'écran
    SDL_SetRenderDrawColor(renderer, 224, 205, 169, 255);

    SDL_RenderClear(renderer);


    const Navigateur& nav = jeu.getConstNavigateur();
    const Ennemi& en = jeu.getConstEnnemi();
    const Shoot& shootn=jeu.getConstshootNav();
    const Shoot& shooten=jeu.getConstshootEn();
    const Shoot& shooteq=jeu.getConstshootEq();
    const Equipage& e=jeu.getConstEquipage();

    sdlDrawTer1();
    sdlDrawTer2();
    sdlDrawTer3();
    sdlDrawTer4();

    im_naviateur.draw(renderer,nav.getPos_x()*TAILLE_SPRITE,nav.getPos_y()*TAILLE_SPRITE,TAILLE_SPRITE*2,TAILLE_SPRITE*2);

    im_projectil1.draw(renderer,shooten.getPos_x()*TAILLE_SPRITE,shooten.getPos_y()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    im_projectil2.draw(renderer,shootn.getPos_x()*TAILLE_SPRITE,shootn.getPos_y()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    im_projectil3.draw(renderer,shooteq.getPos_x()*TAILLE_SPRITE,shooteq.getPos_y()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    im_ennemi.draw(renderer,en.getPos_x()*TAILLE_SPRITE,en.getPos_y()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    im_equipage.draw(renderer,e.getPos_x()*TAILLE_SPRITE,e.getPos_y()*TAILLE_SPRITE, TAILLE_SPRITE,TAILLE_SPRITE);

    //Affichage points de vie navigateur
    SDL_Color color= {0,0,0};
    string V = "PV: " + std::to_string(nav.getVie());
    pvSurface = TTF_RenderText_Solid( font,V.c_str(), color );
    Points_vie=SDL_CreateTextureFromSurface(renderer, pvSurface);
    pvRect.x=10;
    pvRect.y=548;
    SDL_QueryTexture(Points_vie, NULL, NULL, &pvRect.w, &pvRect.h);
    SDL_RenderCopy(renderer, Points_vie, NULL, &pvRect);
    //Affichage score navigateur
    std::string S = "Score : " + std::to_string(nav.getScore());
    ScoreSurface = TTF_RenderText_Solid(font, S.c_str(), color );
    Score=SDL_CreateTextureFromSurface(renderer, ScoreSurface);
    ScoreRect.x=500;
    ScoreRect.y=548;
    SDL_QueryTexture(Score, NULL, NULL, &ScoreRect.w, &ScoreRect.h);
    SDL_RenderCopy(renderer, Score, NULL, &ScoreRect);
    //Affichage chances
    std::string C = "Vies : " + std::to_string(nav.getChance());
    ChanceSurface = TTF_RenderText_Solid(font, C.c_str(), color );
    Chance=SDL_CreateTextureFromSurface(renderer, ChanceSurface);
    chanceRect.x=1025;
    chanceRect.y=548;
    SDL_QueryTexture(Score, NULL, NULL, &chanceRect.w, &chanceRect.h);
    SDL_RenderCopy(renderer, Chance, NULL, &chanceRect);

    //SDL_RenderClear(renderer);
    /*std::string G = "Niveau 1, termine !!";
    VictoireSurface = TTF_RenderText_Solid(font, G.c_str(), color );
    Victoire=SDL_CreateTextureFromSurface(renderer, VictoireSurface);
    VictoireRect.x=500;
    VictoireRect.y=250;
    SDL_QueryTexture(Score, NULL, NULL, &VictoireRect.w, &VictoireRect.h);
    SDL_RenderCopy(renderer, Victoire, NULL, &VictoireRect);*/

    std::string N = "Niveau " + std::to_string(nav.getNiv());
    NiveauSurface = TTF_RenderText_Solid(font, N.c_str(), color );
    Niveau=SDL_CreateTextureFromSurface(renderer, NiveauSurface);
    NiveauRect.x=30;
    NiveauRect.y=30;
    SDL_QueryTexture(Niveau, NULL, NULL, &NiveauRect.w, &NiveauRect.h);
    SDL_RenderCopy(renderer, Niveau, NULL, &NiveauRect);

    //Gestion des niveaux
    jeu.changerNiveau();

}

void sdlJeu::sdlBoucle ()
{
    SDL_Event events;
    bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;

    // tant que ce n'est pas la fin ...
    while (!quit)
    {
        nt = SDL_GetTicks();
        if (nt-t>150)
        {
            jeu.actionsAutomatiques();
            t = nt;
        }

        // tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN)                // Si une touche est enfoncee
            {
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
                    jeu.actionClavier('t');                      // car Y inverse
                    break;
                case SDL_SCANCODE_DOWN:
                    jeu.actionClavier('g');                      // car Y inverse
                    break;
                case SDL_SCANCODE_LEFT:
                    jeu.actionClavier('f');
                    break;
                case SDL_SCANCODE_RIGHT:
                    jeu.actionClavier('h');
                    break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
                default:
                    break;
                }
            }
        }
        //Affichage
        sdlAff();
        SDL_RenderPresent(renderer);

    }
}
