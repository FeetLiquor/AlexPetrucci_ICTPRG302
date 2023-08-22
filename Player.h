#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Asteroid.h"
#include <vector>


class Player
{
public:
    Player(std::vector<Bullet>& bullets_ref, std::vector<Asteroid>* asteroids_ptr);
    void update();
    void render(sf::RenderWindow& window);
    void handle_events(const sf::Event& event);
    sf::Vector2f get_pos();

    int score = 0;

private:
    sf::Sprite _sprite;
    std::vector<Bullet>& _bullets_ref;
    std::vector<Asteroid>* _asteroids_ptr;
};