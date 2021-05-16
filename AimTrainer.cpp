#include <iostream>
#include "AimTrainer.h"

AimTrainer::AimTrainer()
{
    initCircle();
}

void AimTrainer::initCircle()
{
    circle.setRadius(150);
    circle.setPosition(200, 200);
    circle.setFillColor(sf::Color(138, 201, 38));
}

void AimTrainer::draw(sf::RenderTarget *target)
{
    target->draw(circle);

    std::cout << randomTime.asMilliseconds() - clock.getElapsedTime().asMilliseconds() << std::endl;
    if (abs(clock.getElapsedTime().asMilliseconds() - randomTime.asMilliseconds()) < )
    {
        circle.setFillColor(sf::Color::Red);
    }
}

void AimTrainer::start()
{
    srand(time(NULL));
    randomTime = sf::milliseconds(3000 + rand() % 4001);
    clock.restart();
}
