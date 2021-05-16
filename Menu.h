#pragma once
#include "SFML/Graphics.hpp"
class Menu
{
public:
    Menu();

    void render(sf::RenderTarget* target);
    void update();
    void posUp();
    void posDown();
    int getPos();
private:
    sf::Text title;
    sf::Font titleFont;
    sf::Text menuText[3];
    sf::Font menuFont;
    int currentPos = 0;


    void initFonts();
    void initTitle();
    void initMenuText();
};

