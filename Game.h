#pragma once
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "AimTrainer.h"
#include "SpeedTrainer.h"
enum class GameStates { menu, aimTraine, speedTraine};

class Game
{
private:
    //Variables
    Menu menu;
    AimTrainer aimTrainer;
    SpeedTrainer speedTrainer;
    GameStates gameState;
    sf::Event event;
    sf::Int64 deltaTime;

    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    //Private methods
    void initVariables();
    void initWindow();
    void pollEvents();
    void presedRet();
    //void presedKey(sf::Event e, GameStates gameState);
public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Methods
    void update();
    void render();
};