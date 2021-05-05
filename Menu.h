#pragma once
#include "SFML/Graphics.hpp"
class Menu
{
public:
    Menu();
    void draw(sf::RenderWindow& window);
private:
    sf::Text title;
    sf::Font titleFont;
};

