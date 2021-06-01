#pragma once
#include "Trainer.h"

enum class aimTrainerStates
{
    stop, waiting, action
};

class AimTrainer :
    public Trainer
{
public:
    AimTrainer();

    void draw(sf::RenderTarget *target);
    void start();
    void stop();
    bool isClicked(sf::Vector2i mpos);
    bool isStartClicked(sf::Vector2i mpos);
    aimTrainerStates getAimTrainerStates();
   
private:
    aimTrainerStates stateOfAimTrainer;
    sf::Time randomTime;
    int circleState = 0;

    void initCircle();
    void initText();
};

