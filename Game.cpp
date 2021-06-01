#include "Game.h"
#include <iostream>

void Game::initVariables()
{
    window = nullptr;
    gameState = GameStates::menu;
}

void Game::initWindow()
{
    videoMode.height = 600;
    videoMode.width = 800;

    window = new sf::RenderWindow(videoMode, "Aim Nure Trainer", sf::Style::Titlebar | sf::Style::Close);
    
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(false);
}

Game::Game()
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete window; 
}

const bool Game::running() const 
{
    return window->isOpen();
}

void Game::update()
{
    //Event polling
    pollEvents();
}

void Game::render()
{
    window->clear(sf::Color(255, 202, 58));

    switch (gameState)
    {
    case GameStates::menu:
        menu.render(window);
        break;
    case GameStates::aimTraine:
        aimTrainer.draw(window);
        break;
    case GameStates::speedTraine:
        speedTrainer.draw(window);
        break;
    }
    window->display();
}

void Game::updateDeltaTime()
{
    deltaTime = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    deltaTime /= 2000;
}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape && gameState == GameStates::menu)
            {
                window->close();
                break;
            }
            else if (event.key.code == sf::Keyboard::Escape && gameState == GameStates::aimTraine)
            {
                aimTrainer.stop();
                menu.initSounds();
                gameState = GameStates::menu;
                break;

            }
            else if (event.key.code == sf::Keyboard::Escape && gameState == GameStates::speedTraine)
            {
                speedTrainer.stop();
                gameState = GameStates::menu;
                break;
            }
            else if (event.key.code == sf::Keyboard::Up && gameState == GameStates::menu)
            {
                
                menu.posUp();
                break;
            }
            else if (event.key.code == sf::Keyboard::Down && gameState == GameStates::menu)
            {
                menu.posDown();
                break;
            }
            else if (event.key.code == sf::Keyboard::Return && gameState == GameStates::menu)
            {
                switch (menu.getPos())
                {
                case 0:
                    gameState = GameStates::aimTraine;
                    break;
                case 1:
                    gameState = GameStates::speedTraine;
                    break;
                case 2:
                    window->close();
                    break;
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (gameState == GameStates::aimTraine) 
            {
                if (aimTrainer.isStartClicked(mousepos))
                {
                    aimTrainer.getTrainerState() != aimTrainerStates::stop ? aimTrainer.stop() : aimTrainer.start();
                }

                if (aimTrainer.getTrainerState() != aimTrainerStates::stop)
                    aimTrainer.isClicked(mousepos);
                break;
            }
            else if (gameState == GameStates::speedTraine)
            {
                if (speedTrainer.isStartClicked(mousepos))
                {
                    std::cout << "clicl";
                    speedTrainer.getTrainerState() == speedTrainerStates::stop ? speedTrainer.start() : speedTrainer.stop();
                }
                if (speedTrainer.getTrainerState() != speedTrainerStates::stop)
                    speedTrainer.isClicked(mousepos);
                break;
            }
            break;
        }

    }
}
