#pragma once

#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <vector>


class PlayState : public State
{
public:
    PlayState();
    void handle_events(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    Player& get_player();

private:
    Player _player;
    std::vector<Bullet> _bullets;
    std::vector<Asteroid> _asteroids;
    sf::Clock _asteroid_timer;
    sf::Text _score_text;
    float _spawn_time = 2.0f;
};