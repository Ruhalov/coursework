#include <iostream>
#include "AimTrainer.h"

AimTrainer::AimTrainer()
{
    initScoreFont();
    initText();
    initCircle();
    sat = stop;
}

void AimTrainer::initCircle()
{
    circle.setRadius(150);
    circle.setPosition(125, 150);
    circle.setFillColor(sf::Color(138, 201, 38));
}

void AimTrainer::initText()
{
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color(106, 76, 147));
    scoreText.setFont(scoreFont);
    scoreText.setPosition(400, 400);

    startStopText.setCharacterSize(40);
    startStopText.setFillColor(sf::Color(106, 76, 147));
    startStopText.setFont(scoreFont);
    startStopText.setPosition(650, 550);
    startStopText.setString("START");

}

void AimTrainer::draw(sf::RenderTarget *target)
{
    target->draw(circle);
    target->draw(startStopText);

    

    if (abs(randomTime.asMilliseconds() - clock.getElapsedTime().asMilliseconds()) <= 12)
    {
        circle.setFillColor(sf::Color(255, 89, 94));
        sat = action;
        clock.restart();
    }
    target->draw(scoreText);
    
}

void AimTrainer::start()
{
    srand(time(NULL));
    randomTime = sf::milliseconds(3000 + rand() % 4001);
    clock.restart();
}

bool AimTrainer::isClicked(sf::Vector2i mpos)
{
    float distance = hypot((mpos.x - (circle.getPosition().x + circle.getRadius())), (mpos.y - (circle.getPosition().y + circle.getRadius())));
    if (distance <= circle.getRadius())
    {
        circle.setFillColor(sf::Color(138, 201, 38));
        scoreText.setString(std::to_string(clock.getElapsedTime().asMilliseconds()));
        sat = waiting;
        start();
    }
    return true;
}

bool AimTrainer::isStartClicked(sf::Vector2i mpos)
{
    float t = startStopText.getGlobalBounds().top;
    float l = startStopText.getGlobalBounds().left;
    float w = startStopText.getGlobalBounds().width;
    float h = startStopText.getGlobalBounds().height;

    if (sf::IntRect(l, t, w, h).contains(mpos))
    {
        if (sat == waiting || sat == action)
        {
            startStopText.setString("START");
            sat = stop;
            randomTime = sf::milliseconds(0);
        }
        else
        {
            startStopText.setString("STOP");
            sat = waiting;
            start();
        }
        return true;
    }
    return false;
}
