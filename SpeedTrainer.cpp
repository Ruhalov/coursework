#include "SpeedTrainer.h"

SpeedTrainer::SpeedTrainer()
{
        initSideBarFonts();
        initSideBar();
        stateOfSpeedTrainer = speedTrainerStates::stop;
}

void SpeedTrainer::draw(sf::RenderTarget* target)
{
    target->draw(sideBar);
    target->draw(startStopText);
    target->draw(scoreString);
    target->draw(scoreText);
    drawScoreVector(target);
}

void SpeedTrainer::initCircle()
{
}

void SpeedTrainer::start()
{
    startStopText.setString("STOP");
    stateOfSpeedTrainer = speedTrainerStates::action;
    updateSideBar();
}

void SpeedTrainer::stop()
{
    startStopText.setString("START");
    stateOfSpeedTrainer = speedTrainerStates::stop;
    updateSideBar();
}

speedTrainerStates SpeedTrainer::getTrainerState()
{
    return stateOfSpeedTrainer;
}
