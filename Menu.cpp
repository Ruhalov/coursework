#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    if (!titleFont.loadFromFile("fonts/title-font.otf"))
    {
        std::cout << "Can`t load file!";
    }
    title.setString("Nure Aim Trainer");
    title.setFillColor(sf::Color(0, 0, 0));
    title.setCharacterSize(60);
    title.setFont(titleFont);
    float width = title.getGlobalBounds().width;
    title.setPosition(sf::Vector2f(400 - width / 2, 0));
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(title);
    
}
