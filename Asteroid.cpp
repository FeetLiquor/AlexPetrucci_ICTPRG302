#include "Asteroid.h"

#include "ResourceManager.h"
#include "config.h"
#include "utils.h"
#include "RNG.h"


Asteroid::Asteroid(float x, float y, float direction)
    : _move_direction(direction),
    _spin_direction(-1.0 + (2 * RNG::get_int(0, 1)))
{
    _sprite.setTexture(ResourceManager::get_texture("asteroid.png"));
    _sprite.setPosition(x, y);
    _sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
}


void Asteroid::update()
{
    _sprite.rotate(ASTEROID_SPIN_SPEED * _spin_direction);
    _sprite.move(ASTEROID_SPEED * move_x(_move_direction), ASTEROID_SPEED * move_y(_move_direction));

    if (!_sprite.getGlobalBounds().intersects(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)))
    {
        if (_out_of_spawn_bounds)
            should_remove = true;
    }
    else
    {
        _out_of_spawn_bounds = true;
    }
}


void Asteroid::render(sf::RenderWindow& window)
{
    window.draw(_sprite);
    // unncomment below if you want to see hitbox
    //sf::RectangleShape hitbox(sf::Vector2f(get_bounds().width, get_bounds().height));
    //hitbox.setPosition(get_bounds().left, get_bounds().top);
    //window.draw(hitbox);
}


sf::FloatRect Asteroid::get_bounds()
{
    // returns smaller than actuall bounds on purpose for better hitbox
    float bounds_width = _sprite.getGlobalBounds().width * 0.6;
    float bounds_height = _sprite.getGlobalBounds().height * 0.6;
    float bounds_x = _sprite.getGlobalBounds().left + ((_sprite.getGlobalBounds().width - bounds_width) / 2);
    float bounds_y = _sprite.getGlobalBounds().top + ((_sprite.getGlobalBounds().height - bounds_height) / 2);
    return sf::FloatRect(bounds_x, bounds_y, bounds_width, bounds_height);
}