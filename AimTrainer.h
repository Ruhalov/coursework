#pragma once
#include "Trainer.h"
class AimTrainer :
    public Trainer
{
public:
    AimTrainer();

    void draw(sf::RenderTarget *target);
    void start();
    bool isClicked(sf::Vector2i mpos);
    bool isStartClicked(sf::Vector2i mpos);
    enum state
    {
        stop, waiting, action
    };
    state sat;
private:
    sf::Time randomTime;
    int circleState = 0;

    void initCircle();
    void initText();
};

