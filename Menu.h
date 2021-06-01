#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Menu
{
public:
    Menu();

    void render(sf::RenderTarget* target);
    void update();
    void posUp();
    void posDown();
    int getPos();
    void initSounds();
private:
    sf::Text title;
    sf::Font titleFont;
    sf::Text menuText[3];
    sf::Font menuFont;
    sf::Music choseMenuSound;
    sf::Music switchMenuSound;
    int currentPos = 0;


    void initFonts();
    void initTitle();
    void initMenuText();
};

