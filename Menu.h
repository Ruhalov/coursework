#pragma once
#include "SFML/Graphics.hpp"
class Menu
{
public:
    Menu();

    void render(sf::RenderTarget* target);
    int const getState() const;
private:
    int state = 0;
    sf::Text title;
    sf::Font titleFont;

    void initFonts();
    void initTitle();
    void switchState(int s);
};

