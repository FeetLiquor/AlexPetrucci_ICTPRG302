#include "Bullet.h"

#include "ResourceManager.h"
#include "config.h"
#include "utils.h"


Bullet::Bullet(float x, float y, float direction, std::vector<Asteroid>* asteroids_ptr, int* score_ref)
    : _asteroids_ptr(asteroids_ptr),
    _score_ptr(score_ref)
{
    _sprite.setTexture(ResourceManager::get_texture("bullet.png"));
    _sprite.setPosition(x, y);
    _sprite.setRotation(direction);
    _sprite.setScale(0.05f, 0.05f);
    _sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
}


void Bullet::update()
{
    _sprite.move(BULLET_SPEED * move_x(_sprite.getRotation()), BULLET_SPEED * move_y(_sprite.getRotation()));

    if (!_sprite.getGlobalBounds().intersects(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)))
        should_remove = true;

    for (auto& asteroid : *_asteroids_ptr)
    {
        if (_sprite.getGlobalBounds().intersects(asteroid.get_bounds()))
        {
            asteroid.should_remove = true;
            should_remove = true;
            *_score_ptr += 10;
        }
    }
}


void Bullet::render(sf::RenderWindow& window)
{
    window.draw(_sprite);
}