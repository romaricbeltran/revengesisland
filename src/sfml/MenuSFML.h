#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class menuSFML
{
public :
    menuSFML(float width, float height);
    ~menuSFML();

    void draw(sf::RenderWindow & window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private :
    int selectedItemIndex;
    sf::Font font;
    sf::Texture t[MAX_NUMBER_OF_ITEMS];
    sf::Sprite sT[MAX_NUMBER_OF_ITEMS];

    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture titre;
    sf::Sprite sTitre;
    sf::Texture backg;
    sf::Sprite sBackg;
};
