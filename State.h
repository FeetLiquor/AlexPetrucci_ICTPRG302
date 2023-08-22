#pragma once

#include <SFML/Graphics.hpp>


class State
{
public:
    State() {}
    virtual ~State() {}

    virtual void handle_events(const sf::Event& e) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    static State* current;
    static State* start;
    static State* play;
    static State* pause;
    static State* end;
};