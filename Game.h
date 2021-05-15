#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"

class Game
{
private:
    //Variables
    sf::Event event;
    sf::Clock clock;
    Menu menu;
    float deltaTime;

    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    //Private methods
    void initVariables();
    void initWindow();
public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Methods
    void update();
    void updateDeltaTime();
    void pollEvents();
    void render();
};

