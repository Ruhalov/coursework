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
    aimTrainerStates getTrainerState();
   
private:
    aimTrainerStates stateOfAimTrainer;
    sf::Time randomTime;
    int circleState = 0;

    void initCircle();
    void initText();
};

