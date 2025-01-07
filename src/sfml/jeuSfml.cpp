#include <iostream>

#include "jeuSfml.h"
#include <cmath>
#include <list>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace sf;

const int TAILLE_SPRITE = 30;


bool isCollide(Objet *a,Objet *b)
{
    return (b->x - a->x)*(b->x - a->x)+
           (b->y - a->y)*(b->y - a->y)<
           (a->R + b->R)*(a->R + b->R);
}


sfmlJeu::sfmlJeu() : jeu()
{

    int dimx, dimy;
    dimx = jeu.getConstTerrain().getDimX();
    dimy = jeu.getConstTerrain().getDimY();
    dimx = dimx * TAILLE_SPRITE;
    dimy = dimy * TAILLE_SPRITE;
    window.create(sf::VideoMode(dimx, dimy), "Revenge's Island");
    window.setKeyRepeatEnabled(true);

    bande.openFromFile("./data/bande.ogg");
    blood.openFromFile("./data/blood.ogg"); //Ouverture du fichier son
    font.loadFromFile("./data/test.ttf");  //Chargement de la police
    sang.loadFromFile("./data/type_A.png");
    axe.loadFromFile("./data/axe.png");
    ennemy.loadFromFile("./data/navigateur.png");

    tSable.loadFromFile("./data/sable.png");
    tEau.loadFromFile("./data/water.png");
    tPavet.loadFromFile("./data/ground.png");
    boat.loadFromFile("./data/boat.png");
    wreckage.loadFromFile("./data/epave.png");
    rock.loadFromFile("./data/roche.png");
    grass.loadFromFile("./data/herbe.png");
    stoneHouse.loadFromFile("./data/house_stone.png");
    dalle.loadFromFile("./data/dalle.png");
    hachette.loadFromFile("./data/hache.png");
    feu.loadFromFile("./data/fire.png");
    carrelage.loadFromFile("./data/carrelage.png");
    tree.loadFromFile("./data/tree.png");
    boss.loadFromFile("./data/boss.png");


}

sfmlJeu::~sfmlJeu()
{
    window.clear();
}

void sfmlJeu::SfmlAff()
{

    AfficheTerrain();

    //Affiche le premier allié lorsqu'on atteint un certains score
    if(n.aff_allie1==true)
    {
        window.draw(n.sprite_allie1);
    }
    //Affiche le personnage
    window.draw(n.sprite_perso);

    std::ostringstream ssScore;
    ssScore<<"Score : "<<score;

    //Affecte la texture boat au sprite
    spBoat.setTexture(boat);

    //Epave
    spWreckage.setTexture(wreckage);
    spWreckage.setPosition(240,200);
    spWreckage.setScale(sf::Vector2f(0.8,0.8));
    spWreckage.setRotation(25);
    window.draw(spWreckage);

    //Text Score
    text.setFont(font);
    text.setCharacterSize(50);
    text.setString(ssScore.str());
    window.draw(text);

    window.setFramerateLimit(60);


    sGrass.setTexture(grass);
    spStoneHouse.setTexture(stoneHouse);
    spStoneHouse.setPosition(2500,70);
    window.draw(spStoneHouse);

    Animation sEnnemi(ennemy,0,0,72,96,3,0.1);
    Animation sBoss(boss, 0, 0, 103.25,146,4,0.1);
    sBoss.sp.setScale(sf::Vector2f(0.6,0.6));

    int randBoss=100;
    int randennemi=200;
    //Affiche les ennemis

    if(n.aff_allie1==true)
    {
        randennemi=50;

    }
    stop=false;
    //Si le personnage depasse ce points d'abcisse
    if(n.sprite_perso.getPosition().x>=2320)
    {
        stop=true;
    }
    //Si l'ennemi depasse ce points alors on supprimer le premier ennemi
    if(stop==false)
    {
        if (rand()%randennemi==0)
        {
            Boss *b=new Boss();
            b->parametres(sEnnemi, 0,n.sprite_perso.getPosition().y+55, -90, 5);
            en.push_back(b);
        }
    }

    vagueBoss=false;

    if(n.sprite_perso.getPosition().x>2320)
    {
        vagueBoss=true;
    }
    if(vagueBoss==true)
    {
        randBoss=50;
        if (rand()%randBoss==0)
        {
            ennemi *e=new ennemi();
            e->parametres(sBoss, 0,n.sprite_perso.getPosition().y+55, -90, 5);
            sBoss.update();
            en.push_back(e);
        }
    }


    //Efface le sang
    for(auto e:en)
        if (e->nom=="sang")
            if (e->anim.isEnd()) e->vie=0;


    //suppression des element de type Objet*
    for(auto i=en.begin(); i!=en.end();)
    {
        Objet *e=*i;
        e->update();
        e->anim.update();
        if(e->vie==false)
        {
            i=en.erase(i);
            delete e;
        }
        else i++;
    }

    //Affichage des elements de type objet
    for(auto i:en) i->draw(window);
    window.display();

    window.clear(sf::Color(0, 127, 255));

}






void sfmlJeu::SfmlBoucle()
{

    n.sprite_perso.setPosition(300,70);
    n.sprite_perso.setTexture(n.perso);

    n.sprite_allie1.setPosition(200,90);
    n.sprite_allie1.setScale(0.7,0.7);
    n.sprite_allie1.setTexture(n.allie);


    //Creation des animations
    Animation sSang(sang, 0,0,512,512, 6, 0.2);
    Animation sHache(axe,  0,0,64,64,16,0.4);
    Animation sBoat(boat, 0,0,127,103,3,0.08);
    Animation sFire(feu, 0,0,64,145,8,0.4);
    Animation sEnnemi(ennemy,0,0,72,96,3,0.1);
    Animation sHachette(hachette, 0,0,64,64,16,0.3);
    bool wait=false;

    bande.play();
    bande.setLoop(true);

    while (window.isOpen()) //Ouverture Boucle d'Evenements
    {


        int speed=10;
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyReleased:
                if(event.key.code==Keyboard::Space)
                {
                    hache *b= new hache();
                    b->parametres(sHache, n.sprite_perso.getPosition().x+50, n.sprite_perso.getPosition().y+70, angle_tir, 25);
                    en.push_back(b);

                    if(n.can_shoot1==true)
                    {
                        hache *h= new hache();

                        h->parametres(sHachette, n.sprite_allie1.getPosition().x+20, n.sprite_allie1.getPosition().y+50, angle_tir, 5);
                        en.push_back(h);
                    }

                }

                break;

            case Event::KeyPressed:
                n.updateFPS=true;
                if(event.key.code==Keyboard::Escape)
                    window.close();
                if(event.key.code==Keyboard::P)
                    wait = !wait;
                else if(event.key.code==Keyboard::Up)
                {
                    n.sprite_perso.move(0,-speed);
                    n.sprite_allie1.setPosition(n.sprite_perso.getPosition().x, n.sprite_perso.getPosition().y+70);
                    n.sprite_allie1.move(0, -speed);
                    n.anim.y=n.Up;
                }

                else if(event.key.code==Keyboard::Down)
                {
                    n.sprite_perso.move(0,speed);
                    n.sprite_allie1.setPosition(n.sprite_perso.getPosition().x, n.sprite_perso.getPosition().y-30);
                    n.sprite_allie1.move(0, speed);
                    n.anim.y=n.Down;
                    angle_tir=90;

                }
                else if(event.key.code==Keyboard::Left)
                {
                    n.sprite_perso.move(-speed,0);
                    n.sprite_allie1.setPosition(n.sprite_perso.getPosition().x+60, n.sprite_perso.getPosition().y);
                    n.sprite_allie1.move(-speed, 0);
                    n.anim.y=n.Left;
                    angle_tir=180;

                }
                else if(event.key.code==Keyboard::Right)
                {
                    n.sprite_perso.move(speed,0);
                    n.sprite_allie1.setPosition(n.sprite_perso.getPosition().x-40, n.sprite_perso.getPosition().y);
                    n.sprite_allie1.move(speed, 0);
                    n.anim.y=n.Right;
                    angle_tir=360;
                }
            default:
                break;



            }
            //Collision hache vs ennemi
            for(auto a:en)
                for(auto b:en)
                {
                    if ((a->nom=="ennemi"||a->nom=="boss") && (b->nom=="hache"))
                        if ( isCollide(a,b) )
                        {
                            a->vie=false;
                            b->vie=false;
                            Objet *e = new Objet();
                            e->parametres(sSang,a->x,a->y,0,1);
                            e->nom="sang";
                            blood.play();
                            score=score+5;
                            en.push_back(e);
                        }

                }


            //Appel procédures
            n.FpsPerso();
            n.CameraPerso();
            window.setView(n.view);

            if(score>=100)
            {
                n.aff_allie1=true;
                n.can_shoot1=true;
                cout<<"Niveau 1 fini "<<endl;
            }
            if(score>=200)
            {
                cout<<"Niveau 2 fini "<<endl;
                window.clear();
                cout.rdbuf(NULL);
            }

        }

        /*Objet *b=new Objet();
        b->parametres(sBoat, 500,270,-90,5);
        sBoat.update();
        b->nom="boat";
        en.push_back(b);*/

        /*Objet *d=new Objet();
        d->parametres(sFire, 1645,295,-90,50);
        sFire.sp.setScale(sf::Vector2f(0.35,0.35));
        d->nom="feu";
        en.push_back(d);*/


        SfmlAff();
    }



}



void sfmlJeu::AfficheTerrain()
{

    std::vector<sf::Sprite> sable(15, sf::Sprite(tSable));
    std::vector<sf::Sprite> eau(15, sf::Sprite(tEau));
    std::vector<sf::Sprite> pavet(9, sf::Sprite(tPavet));
    std::vector<sf::Sprite> Grass(40, sf::Sprite(grass));
    std::vector<sf::Sprite> sDalle(15, sf::Sprite(dalle));
    std::vector<sf::Sprite> sCar(15, sf::Sprite(carrelage));




    for(unsigned int j=0; j<sable.size(); j++)
        for (unsigned int i = 0; i < sable.size(); i++)
        {
            sable[i].setPosition((j*jeu.getConstTerrain().getDimX()*2.5)+400,i*jeu.getConstTerrain().getDimY()*2);
            window.draw(sable[i]);

        }

    for(unsigned int g=0; g<Grass.size(); g++)
        for(unsigned int h=0; h<Grass.size(); h++)
        {
            Grass[h].setPosition((g*jeu.getConstTerrain().getDimX()*0.6)+1400, h*jeu.getConstTerrain().getDimY()*1.25);
            Grass[h].setScale(sf::Vector2f(0.8,0.79));
            window.draw(Grass[h]);
        }

    std::vector<sf::Sprite> spTree(5, sf::Sprite(tree));

    for(unsigned int x=0; x< spTree.size(); x++)
        for (unsigned int y = 0; y < spTree.size(); y++)
        {
            spTree[y].setPosition((jeu.getConstTerrain().getDimX() * x * 5) + 1500, (jeu.getConstTerrain().getDimY() * y * 7) + 200);
            window.draw(spTree[y]);
        }

    for(unsigned int x=0; x<eau.size(); x++)
        for (unsigned int y = 0; y < eau.size(); y++)
        {
            eau[y].setPosition(x*jeu.getConstTerrain().getDimX()*2,y*jeu.getConstTerrain().getDimY()*3);
            window.draw(eau[y]);

            eau[y].setPosition((x*jeu.getConstTerrain().getDimX()*1.25)+3600, y*jeu.getConstTerrain().getDimY()*2.8);
            window.draw(eau[y]);

        }

    for(unsigned int z=0; z<pavet.size(); z++)
        for (unsigned int t = 0; t < pavet.size(); t++)
        {
            pavet[t].setPosition((z*jeu.getConstTerrain().getDimX()*3.2)+198,100);
            window.draw(pavet[t]);

        }

    for(unsigned int c=0; c<sDalle.size(); c++)
        for(unsigned int v=0; v<sDalle.size(); v++)
        {
            sDalle[v].setPosition((c*jeu.getConstTerrain().getDimX()*1.25)+2300, v*jeu.getConstTerrain().getDimY()*3);
            //Grass[v].setScale(sf::Vector2f(0.5,0.5));
            sDalle[v].setScale(0.2,0.2);
            window.draw(sDalle[v]);
        }

    for(unsigned int b=0; b<sCar.size(); b++)
        for(unsigned int n=0; n<sCar.size(); n++)
        {
            sCar[n].setPosition((b*jeu.getConstTerrain().getDimX()*1.25)+3100, n*jeu.getConstTerrain().getDimY()*2.8);
            //Grass[v].setScale(sf::Vector2f(0.5,0.5));
            sCar[n].setScale(0.2,0.2);
            window.draw(sCar[n]);
        }
}
