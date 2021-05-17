#include "Trainer.h"

void Trainer::initScoreFont()
{
    if (!scoreFont.loadFromFile("fonts/score-font.otf"))
    {
        throw ("Could not load font file: \"score-font.otf\"");
    }
}

void Trainer::initSideBar()
{
    startStopText.setCharacterSize(40);
    startStopText.setFillColor(sf::Color(106, 76, 147));
    startStopText.setFont(scoreFont);
    startStopText.setPosition(650, 550);
    startStopText.setString("START");

    sideBar.setSize(sf::Vector2f(200, 600));
    sideBar.setFillColor(sf::Color(25, 130, 196));
    sideBar.setPosition(sf::Vector2f(600, 0));
}
