#include "Player.h"

#include "config.h"
#include "ResourceManager.h"
#include "utils.h"
#include "State.h"
#include <iostream>


Player::Player(std::vector<Bullet>& bullets_ref, std::vector<Asteroid>* asteroids_ptr)
    : _bullets_ref(bullets_ref),
_asteroids_ptr(asteroids_ptr)
{
    _sprite.setTexture(ResourceManager::get_texture("spaceship.png"));
    _sprite.setScale(0.1f, 0.1f);
    _sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
    _sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}


void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _sprite.rotate(-PLAYER_TURN_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _sprite.rotate(PLAYER_TURN_SPEED);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _sprite.move(PLAYER_SPEED * move_x(_sprite.getRotation()), PLAYER_SPEED * move_y(_sprite.getRotation()));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _sprite.move(-PLAYER_SPEED * move_x(_sprite.getRotation()), -PLAYER_SPEED * move_y(_sprite.getRotation()));

    if (!sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT).contains(_sprite.getPosition()))
    {
        _sprite.move(PLAYER_SPEED * move_x(_sprite.getRotation()), PLAYER_SPEED * move_y(_sprite.getRotation()));
        if (!sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT).contains(_sprite.getPosition()))
            _sprite.move(-2 * PLAYER_SPEED * move_x(_sprite.getRotation()), -2 * PLAYER_SPEED * move_y(_sprite.getRotation()));
    }

    for (auto& asteroid : *_asteroids_ptr)
    {
        if (_sprite.getGlobalBounds().intersects(asteroid.get_bounds()))
            State::current = State::end;
    }
}


void Player::render(sf::RenderWindow& window)
{
    window.draw(_sprite);
}


void Player::handle_events(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            float bullet_spawn_x = _sprite.getPosition().x + (move_x(_sprite.getRotation()) * (_sprite.getGlobalBounds().width / 2));
            float bullet_spawn_y = _sprite.getPosition().y + (move_y(_sprite.getRotation()) * (_sprite.getGlobalBounds().height / 2));
            _bullets_ref.push_back(Bullet(bullet_spawn_x, bullet_spawn_y, _sprite.getRotation(), _asteroids_ptr, &score));
        }
    }
}


sf::Vector2f Player::get_pos()
{
    return _sprite.getPosition();
}