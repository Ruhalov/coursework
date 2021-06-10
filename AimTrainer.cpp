#include <iostream>
#include "AimTrainer.h"
#include <string>

AimTrainer::AimTrainer()
{
    initSideBarFonts();
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

    if (abs(randomTime.asMilliseconds() - clock.getElapsedTime().asMilliseconds()) <= 12 && stateOfAimTrainer == aimTrainerStates::waiting)
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
    randomTime = sf::milliseconds(2000 + rand() % 5001);
    std::cout << "rand time " << randomTime.asMilliseconds() << std::endl;
    startStopText.setString("STOP");
    startStopText.setFillColor(sf::Color(255, 89, 94));
    stateOfAimTrainer = aimTrainerStates::waiting;
    clock.restart();
    updateSideBar();
}

void AimTrainer::stop()
{
    startStopText.setString("START");
    startStopText.setFillColor(sf::Color(138, 201, 38));
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
        std::cout << "time " << clock.getElapsedTime().asMilliseconds();
        scoreText.setString(std::to_string(clock.getElapsedTime().asMilliseconds()));
        std::string tmpScore = std::to_string(clock.getElapsedTime().asMilliseconds()) + " ms.";
        if (scoreVectorCounter != scoreVector.size() - 1)
        {
            scoreVector[scoreVectorCounter].setString(tmpScore);
            scoreVectorCounter++;
        }
        else
        {
            if (!scoreVector[scoreVectorCounter].getString().isEmpty())
            {
                for (int i = 1; i < scoreVector.size(); i++)
                {
                    scoreVector[i - 1] = scoreVector[i];
                }
            }
            scoreVector[scoreVectorCounter].setString(tmpScore);
        }
        stateOfAimTrainer = aimTrainerStates::waiting;
        start();
        return true;
    }
    return false;
}

aimTrainerStates AimTrainer::getTrainerState()
{
    return stateOfAimTrainer;
}
