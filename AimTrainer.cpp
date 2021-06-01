#include <iostream>
#include "AimTrainer.h"

AimTrainer::AimTrainer()
{
    initScoreFont();
    initText();
    initCircle();
    initSideBar();
    stateOfAimTrainer = aimTrainerStates::stop;
    srand(time(NULL));
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
}

void AimTrainer::draw(sf::RenderTarget *target)
{
    target->draw(circle);
    target->draw(sideBar);
    target->draw(startStopText);

    if (abs(randomTime.asMilliseconds() - clock.getElapsedTime().asMilliseconds()) <= 12)
    {
        circle.setFillColor(sf::Color(255, 89, 94));
        stateOfAimTrainer = aimTrainerStates::action;
        clock.restart();
    }
    target->draw(scoreString);
    target->draw(scoreText);
    drawScoreVector(target);
    
}

void AimTrainer::start()
{
    randomTime = sf::milliseconds(3000 + rand() % 4001);
    std::cout << "rand time " << randomTime.asMilliseconds();
    startStopText.setString("STOP");
    stateOfAimTrainer = aimTrainerStates::waiting;
    clock.restart();
    updateSideBar();
}

void AimTrainer::stop()
{
    startStopText.setString("START");
    stateOfAimTrainer = aimTrainerStates::stop;
    circle.setFillColor(sf::Color(138, 201, 38));
    randomTime = sf::milliseconds(0);
    updateSideBar();
}

bool AimTrainer::isClicked(sf::Vector2i mpos)
{
    float distance = hypot((mpos.x - (circle.getPosition().x + circle.getRadius())), (mpos.y - (circle.getPosition().y + circle.getRadius())));
    if (distance <= circle.getRadius() && stateOfAimTrainer == aimTrainerStates::action)
    {
        circle.setFillColor(sf::Color(138, 201, 38));
        scoreText.setString(std::to_string(clock.getElapsedTime().asMilliseconds()));
        if (scoreVectorCounter < scoreVector.size() - 1)
        {
        scoreVector[scoreVectorCounter].setString((std::to_string(clock.getElapsedTime().asMilliseconds())));
        scoreVectorCounter++;
        }
        else
        {
            scoreVector[scoreVectorCounter].setString((std::to_string(clock.getElapsedTime().asMilliseconds())));
            for (int i = 1; i < scoreVector.size() - 1; i++)
            {
                scoreVector[i -1] = scoreVector[i];
            }
        }
        stateOfAimTrainer = aimTrainerStates::waiting;
        start();
        return true;
    }
    return false;
}

bool AimTrainer::isStartClicked(sf::Vector2i mpos)
{
    int t = startStopText.getGlobalBounds().top;
    int l = startStopText.getGlobalBounds().left;
    int w = startStopText.getGlobalBounds().width;
    int h = startStopText.getGlobalBounds().height;

    if (sf::IntRect(l, t, w, h).contains(mpos))
    {
        stateOfAimTrainer != aimTrainerStates::stop ? stop() : start();
        return true;
    }
    return false;
}

aimTrainerStates AimTrainer::getAimTrainerStates()
{
    return stateOfAimTrainer;
}
