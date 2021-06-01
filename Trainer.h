#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Trainer
{
public:
protected:
    sf::CircleShape circle;
    sf::RectangleShape sideBar;
    sf::Font scoreFont;
    sf::Text scoreText;
    sf::Text scoreString;
    sf::Text startStopText;
    sf::Text st0, st1, st2, st3, st4;
    std::vector<sf::Text> scoreVector{st0, st1, st2, st3 ,st4};
    int scoreVectorCounter = 0;
    sf::Clock clock;

    void initScoreFont();
    void initSideBar();
    void updateSideBar();
    void drawScoreVector(sf::RenderTarget*t);
private:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void draw(sf::RenderTarget* target) = 0;
};

