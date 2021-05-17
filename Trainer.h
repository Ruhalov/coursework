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
    sf::RectangleShape sideBar;

    void initScoreFont();
    void initSideBar();
private:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void draw(sf::RenderTarget* target) = 0;

};

