#include <random>
#include <iostream>
#include "SpeedTrainer.h"

SpeedTrainer::SpeedTrainer()
{
    initCircle();
    initSideBarFonts();
    initSideBar();
    initText();
    stateOfSpeedTrainer = speedTrainerStates::stop;
    srand(time(NULL));
    iter = 0;
}

void SpeedTrainer::draw(sf::RenderTarget* target)
{
    target->draw(sideBar);
    target->draw(startStopText);
    target->draw(scoreString);
    target->draw(scoreText);
    drawScoreVector(target);
    target->draw(circle);
    if (circle.getRadius() > 0 && stateOfSpeedTrainer == speedTrainerStates::action)
        circle.setRadius(circle.getRadius() - (iter / 30.));
    else
        stop();
}

void SpeedTrainer::initCircle()
{
    iter = 0;
    circle.setRadius(30);
    circle.setPosition(270, 270);
    circle.setFillColor(sf::Color(138, 201, 38));
}

void SpeedTrainer::start()
{
    initCircle();
    startStopText.setString("STOP");
    startStopText.setFillColor(sf::Color(255, 89, 94));
    stateOfSpeedTrainer = speedTrainerStates::action;
    updateSideBar();
}

void SpeedTrainer::stop()
{
    initCircle();
    startStopText.setString("START");
    startStopText.setFillColor(sf::Color(138, 201, 38));
    stateOfSpeedTrainer = speedTrainerStates::stop;
    updateSideBar();
}

int SpeedTrainer::randPos()
{
    return 25 + rand() % 515;
}

bool SpeedTrainer::isClicked(sf::Vector2i mpos)
{
    float distance = hypot((mpos.x - (circle.getPosition().x + circle.getRadius())), (mpos.y - (circle.getPosition().y + circle.getRadius())));
    if (distance <= circle.getRadius() && stateOfSpeedTrainer == speedTrainerStates::action)
    {
        circle.setRadius(30);
        circle.setPosition(randPos(), randPos());
        std::cout << iter<<"\n";
        scoreText.setString(std::to_string(iter));
        float widthScoreText = scoreText.getGlobalBounds().width;
        scoreText.setPosition(700 - widthScoreText / 2, 80);
        ++iter;
        return true;
    }
    return false;
}

void SpeedTrainer::initText()
{
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color(106, 76, 147));
    scoreText.setFont(scoreFont);
}

speedTrainerStates SpeedTrainer::getTrainerState()
{
    return stateOfSpeedTrainer;
}
