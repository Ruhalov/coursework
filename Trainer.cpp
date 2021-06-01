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
    startStopText.setString("START");
    float widthStartStopText = startStopText.getGlobalBounds().width;
    startStopText.setPosition(700 - widthStartStopText / 2, 550);

    sideBar.setSize(sf::Vector2f(200, 600));
    sideBar.setFillColor(sf::Color(25, 130, 196));
    sideBar.setPosition(sf::Vector2f(600, 0));

    scoreString.setCharacterSize(40);
    scoreString.setFillColor(sf::Color(106, 76, 147));
    scoreString.setFont(scoreFont);
    scoreString.setString("Score:");
    float widthScoreString = scoreString.getGlobalBounds().width;
    scoreString.setPosition(700 - widthScoreString / 2, 20);

    for (int i = 0; i < scoreVector.size(); i++)
    {
        scoreVector[i].setCharacterSize(40);
        scoreVector[i].setFillColor(sf::Color(106, 76, 147));
        scoreVector[i].setFont(scoreFont);
    }
}
void Trainer::updateSideBar()
{
    float w = startStopText.getGlobalBounds().width;
    startStopText.setPosition(700 - w / 2, 550);
}

void Trainer::drawScoreVector(sf::RenderTarget*t)
{
    for (int i = 0; i < scoreVector.size(); i++)
    {
        float widthScoreString = scoreVector[i].getGlobalBounds().width;
        scoreVector[i].setPosition(700 - widthScoreString / 2, 50 * i + 80);
        t->draw(scoreVector[i]);
    }
}
