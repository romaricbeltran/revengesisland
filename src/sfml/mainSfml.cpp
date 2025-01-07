#include "jeuSfml.h"
#include "MenuSFML.h"

int main (int argc, char** argv)
{

    sfmlJeu sf;
    menuSFML menu(sf.window.getSize().x, sf.window.getSize().y);

    while (sf.window.isOpen())
    {
        sf::Event event;

        while (sf.window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        sf.SfmlBoucle();
                        break;
                    case 1:
                        std::cout<<"Vous avez appuyé sur options ";
                        break;
                    case 2:
                        sf.window.close();
                        break;
                    }
                default:
                    break;
                }

                break;
            case sf::Event::Closed:
                sf.window.close();

            default:
                break;

            }
        }

        sf.window.clear();
        menu.draw(sf.window);

        sf.window.display();
    }


    return 0;
}
