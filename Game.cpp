#include "Game.h"
#include <iostream>

void Game::initVariables()
{
    window = nullptr;
    state = 0;
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

    switch (state)
    {
    case 0:
        menu.render(window);
        break;
    case 1:
        aimTrainer.draw(window);
        break;
    }

    window->display();
}

void Game::updateDeltaTime()
{
    deltaTime = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    deltaTime /= 20;
}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape && state == 0)
            {
                window->close();
                break;
            }
            else if (event.key.code == sf::Keyboard::Escape && state != 0)
            {
                state = 0;
                break;
            }
            else if (event.key.code == sf::Keyboard::Up && state == 0)
            {
                menu.posUp();
            }
            else if (event.key.code == sf::Keyboard::Down && state == 0)
            {
                menu.posDown();
            }
            else if (event.key.code == sf::Keyboard::Return && state == 0)
            {
                switch (menu.getPos())
                {
                case 0:
                    std::cout << "game1";
                    state = 1;
                    aimTrainer.start();
                    break;
                case 1:
                    std::cout << "game2";
                    state = 2;
                    break;
                case 2:
                    window->close();
                    break;
                }

            }
            break;
        }
    }
}
