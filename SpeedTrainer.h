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
    bool isClicked(sf::Vector2i mpos);
    void initText();
    speedTrainerStates getTrainerState();
private:
    int iter;
    speedTrainerStates stateOfSpeedTrainer;
    int randPos();
};

