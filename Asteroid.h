#pragma once

#include <SFML/Graphics.hpp>


class Asteroid
{
public:
    Asteroid(float x, float y, float direction);
    void update();
    void render(sf::RenderWindow& window);
    sf::FloatRect get_bounds();

    bool should_remove = false;

private:
    sf::Sprite _sprite;
    float _move_direction;
    float _spin_direction;
    bool _out_of_spawn_bounds = false;
};