#pragma once
#include "Trainer.h"
class AimTrainer :
    public Trainer
{
public:
    AimTrainer();

    void draw(sf::RenderTarget *target);
    void start();
private:
    sf::Time randomTime;

    void initCircle();
};

