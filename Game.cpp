#include "Game.h"

#include "config.h"


Game::Game()
    : _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
{
    _window.setFramerateLimit(FPS);
}


void Game::run()
{
    while (_window.isOpen())
    {
        handle_events();
        update();
        render();
    }
}


void Game::handle_events()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        State::current->handle_events(event);
    }
}


void Game::update()
{
    State::current->update();
}


void Game::render()
{
    State::current->render(_window);
}
