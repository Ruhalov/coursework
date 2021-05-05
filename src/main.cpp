#include "SFML/Graphics.hpp"
#include "../Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Coursework!");
    Menu menu;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(242, 232, 201));
        menu.draw(window);
        window.display();
    }
	return 0;
}