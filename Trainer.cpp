#include "Trainer.h"

void Trainer::initSideBarFonts()
{
    if (!scoreFont.loadFromFile("fonts/score-font.otf"))
    {
        throw ("Could not load font file: \"score-font.otf\"");
    }
    if (!startStopFont.loadFromFile("fonts/startstop-font.ttf"))
    {
        throw ("Could not load font file: \"startstop-font.ttf\"");
    }
}

void Trainer::initSideBar()
{
    startStopText.setCharacterSize(60);
    startStopText.setFillColor(sf::Color(106, 76, 147));
    startStopText.setFont(startStopFont);
    startStopText.setString("START");
    float widthStartStopText = startStopText.getGlobalBounds().width;
    startStopText.setPosition(700 - widthStartStopText / 2, 530);

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
        scoreVector[i].setCharacterSize(30);
        scoreVector[i].setFillColor(sf::Color(106, 76, 147));
        scoreVector[i].setFont(scoreFont);
    }
}
void Trainer::updateSideBar()
{
    float w = startStopText.getGlobalBounds().width;
    startStopText.setPosition(700 - w / 2, 530);
}

void Trainer::drawScoreVector(sf::RenderTarget*t)
{
    for (int i = 0; i < scoreVector.size(); i++)
    {
        float widthScoreString = scoreVector[i].getGlobalBounds().width;
        scoreVector[i].setPosition(770 - widthScoreString, 40 * i + 80);
        t->draw(scoreVector[i]);
    }
}

bool Trainer::isStartClicked(sf::Vector2i mpos)
{
    float t = startStopText.getGlobalBounds().top;
    float l = startStopText.getGlobalBounds().left;
    float w = startStopText.getGlobalBounds().width;
    float h = startStopText.getGlobalBounds().height;

    if (sf::IntRect(l, t, w, h).contains(mpos))
    {
        return true;
    }
    return false;
}
