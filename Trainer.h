#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Trainer
{
public:
    bool isStartClicked(sf::Vector2i mpos);
protected:
    sf::CircleShape circle;
    sf::RectangleShape sideBar;
    sf::Font scoreFont;
    sf::Font startStopFont;
    sf::Text scoreText;
    sf::Text scoreString;
    sf::Text startStopText;
    sf::Text st0, st1, st2, st3, st4;
    std::vector<sf::Text> scoreVector{st0, st1, st2, st3 ,st4};
    int scoreVectorCounter = 0;
    sf::Text averange;
    sf::Clock clock;

    void initSideBarFonts();
    void initSideBar();
    void updateSideBar();
    void drawScoreVector(sf::RenderTarget*t);
private:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void initCircle() = 0;
    virtual void draw(sf::RenderTarget* target) = 0;
};

