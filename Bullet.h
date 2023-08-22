#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Asteroid.h"


class Bullet
{
public:
    Bullet(float x, float y, float direction, std::vector<Asteroid>* asteroids_ptr, int* score_ref);
    void update();
    void render(sf::RenderWindow& window);

    bool should_remove = false;

private:
    sf::Sprite _sprite;
    std::vector<Asteroid>* _asteroids_ptr;
    int* _score_ptr;
};