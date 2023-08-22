#pragma once

#include <SFML/Graphics.hpp>
#include "StartState.h"


class Game
{
public:
    Game();
    void run();

private:
    void handle_events();
    void update();
    void render();

    sf::RenderWindow _window;
};