#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    initFonts();
    initTitle();
    initMenuText();
    initSounds();
    update();
}

void Menu::posUp()
{
    currentPos == 0 ? currentPos = 2 : --currentPos;
    switchMenuSound.play();
    update();
}

void Menu::posDown()
{
    currentPos++;
    switchMenuSound.play();
    update();
}

int Menu::getPos()
{
    choseMenuSound.play();
    return abs(currentPos % 3);
}

void Menu::initFonts()
{
    if (!titleFont.loadFromFile("fonts/title-font.otf"))
    {
        throw ("Could not load font file: \"title-font.otf\"");
    }
    if (!menuFont.loadFromFile("fonts/menu-font.ttf"))
    {
        throw ("Could not load font file: \"menu-font.ttf\"");
    }
}

void Menu::initTitle()
{
    title.setString("Nure Aim Trainer");
    title.setFillColor(sf::Color(255, 89, 94));
    title.setCharacterSize(60);
    title.setFont(titleFont);
    float width = title.getGlobalBounds().width;
    title.setPosition(sf::Vector2f(400 - width / 2, 20));
}

void Menu::initMenuText()
{
    menuText[0].setString("Game 1");
    menuText[1].setString("Game 2");
    menuText[2].setString("Exit");
    float width;
    for (int i = 0; i < 3; i++)
    {
        menuText[i].setFont(menuFont);
        menuText[i].setCharacterSize(40);
    }
    
}

void Menu::initSounds()
{
    if (!switchMenuSound.openFromFile("sounds/switch-sound.ogg"))
    {
        throw ("Could not load sound file: \"switch-sound.ogg\"");
    }
    if (!choseMenuSound.openFromFile("sounds/chose-sound.ogg"))
    {
        throw("Could not load sound file: \"sounds/chose-sound.ogg\"");
    }
}

void Menu::render(sf::RenderTarget* target = nullptr)
{
    target->draw(title);
    for (int i = 0; i < 3; i++)
    {
        target->draw(menuText[i]);
    }
}

void Menu::update()
{
    float width;
    for (int i = 0; i < 3; i++)
    {
        if (abs(currentPos % 3) == i)
        {
            menuText[i].setScale(1.4, 1.4);
            menuText[i].setFillColor(sf::Color(106, 76, 147));
            width = menuText[i].getGlobalBounds().width;
            menuText[i].setPosition(sf::Vector2f((800 / 2) - (width) / 2, (((800 / 3) * (i + 1)) / 2) + 40));
        }
        else
        {
            menuText[i].setScale(1, 1);
            menuText[i].setFillColor(sf::Color(25, 130, 196));
            width = menuText[i].getGlobalBounds().width;
            menuText[i].setPosition(sf::Vector2f((800 / 2) - (width) / 2, (((800 / 3) * (i + 1)) / 2) + 40));
        }
    }
}


