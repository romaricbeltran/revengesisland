#include "MenuSFML.h"

menuSFML::menuSFML(float width, float height)
{
    titre.loadFromFile("./data/titre.png");
    sTitre.setTexture(titre);

    backg.loadFromFile("./data/background.png");
    sBackg.setTexture(backg);
    sBackg.setScale(0.8,0.8);

    sTitre.setPosition(sf::Vector2f(width/3.5,10));
    t[0].loadFromFile("./data/jouer.png");
    sT[0].setTexture(t[0]);
    sT[0].setPosition(sf::Vector2f(width/2.5, height/(MAX_NUMBER_OF_ITEMS+1)*1));

     t[1].loadFromFile("./data/options.png");
    sT[1].setTexture(t[1]);
    sT[1].setPosition(sf::Vector2f(width/2.5, height/(MAX_NUMBER_OF_ITEMS+1)*2));

     t[2].loadFromFile("./data/quitter.png");
    sT[2].setTexture(t[2]);
    sT[2].setPosition(sf::Vector2f(width/2.5, height/(MAX_NUMBER_OF_ITEMS+1)*3));

}

menuSFML::~menuSFML()
{

}

void menuSFML::draw(sf::RenderWindow &window)
{   window.draw(sBackg);
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++)
    {

        window.draw(sT[i]);
        window.draw(sTitre);

    }
}

void menuSFML::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setScale(1,1);
		selectedItemIndex--;
        menu[selectedItemIndex].setScale(1.2,1.2);
	}
}

void menuSFML::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setScale(1,1);
		selectedItemIndex++;
        menu[selectedItemIndex].setScale(1.2,1.2);;
	}
}
