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
    aimTrainerStates getTrainerState();
    bool isClicked(sf::Vector2i mpos);
   
private:
    aimTrainerStates stateOfAimTrainer;
    sf::Time randomTime;

    void initCircle();
    void initText();
};

