#pragma once
#include "Trainer.h"

enum class speedTrainerStates
{
    stop, action
};

class SpeedTrainer :
    public Trainer
{
public:
    SpeedTrainer();

    void draw(sf::RenderTarget* target);
    void initCircle();
    void start();
    void stop();
    speedTrainerStates getTrainerState();
private:
    speedTrainerStates stateOfSpeedTrainer;
};

