#include <iostream>
#include "Menu.h"


Menu::Menu()
{
    initFonts();
    initTitle();
}

void Menu::initFonts()
{
    if (!titleFont.loadFromFile("fonts/title-font.otf"))
    {
        throw ("Could not load font file!");
    }
}

void Menu::initTitle()
{
    title.setString("Nure Aim Trainer");
    title.setFillColor(sf::Color(0, 0, 0));
    title.setCharacterSize(60);
    title.setFont(titleFont);
    float width = title.getGlobalBounds().width;
    title.setPosition(sf::Vector2f(400 - width / 2, 0));
}

void Menu::switchState(int s)
{
    state = s;
}

void Menu::render(sf::RenderTarget* target = nullptr)
{
    target->draw(title);
}

int const Menu::getState() const
{
    return state;
}

