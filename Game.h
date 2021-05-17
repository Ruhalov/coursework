#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "AimTrainer.h"

enum class GameStates { menu, aimTraine, anothergame};

class Game
{
private:
    //Variables
    sf::Event event;
    sf::Clock clock;
    Menu menu;
    AimTrainer aimTrainer;
    int deltaTime;
    GameStates gameState;

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

