#pragma once
#include "SFML/Graphics.hpp"
class Trainer
{
public:
protected:
    sf::CircleShape circle;
    sf::Text scoreText;
    sf::Font scoreFont;
    sf::Clock clock;
private:
    virtual void start() = 0;
};

