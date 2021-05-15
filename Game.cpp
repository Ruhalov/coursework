#include "Game.h"
#include <iostream>

void Game::initVariables()
{
    window = nullptr;
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
    window->clear(sf::Color::Blue);

    switch (menu.getState())
    {
    case 0:
        menu.render(window);
    case 1:
        std::cout << "game1";
    }

    window->display();
}

void Game::updateDeltaTime()
{
    deltaTime = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    deltaTime /= 1000;
    system("cls");
    std::cout << deltaTime;

}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case (sf::Event::Closed):
            window->close();
            break;
        }
    }
}
