#pragma once
#include "SFML/Graphics.hpp"
class Trainer
{
public:
protected:
    sf::CircleShape circle;
    sf::Text scoreText;
    sf::Text startStopText;
    sf::Font scoreFont;
    sf::Clock clock;

    void initScoreFont();
private:
    virtual void start() = 0;
};

