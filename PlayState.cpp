#include "PlayState.h"

#include "RNG.h"
#include "config.h"
#include "utils.h"
#include "ResourceManager.h"


PlayState::PlayState()
    : _player(_bullets, &_asteroids)
{
    _score_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));
    _score_text.setCharacterSize(32);
}


void PlayState::handle_events(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
            State::current = State::pause;
    }

    _player.handle_events(event);
}


void PlayState::update()
{
    _player.update();

    for (auto bullet_it = _bullets.begin(); bullet_it != _bullets.end(); bullet_it++)
    {
        bullet_it->update();
        if (bullet_it->should_remove)
        {
            _bullets.erase(bullet_it);
            break;
        }
    }

    if (_asteroid_timer.getElapsedTime().asSeconds() > _spawn_time)
    {
        _asteroid_timer.restart();
        float asteroid_spawn_x = 0, asteroid_spawn_y = 0;
        switch (RNG::get_int(1, 4))
        {
        case 1:
            asteroid_spawn_x = -50.f;
            asteroid_spawn_y = RNG::get_float(0, WINDOW_HEIGHT);
            break;
        case 2:
            asteroid_spawn_x = WINDOW_WIDTH + 50.f;
            asteroid_spawn_y = RNG::get_float(0, WINDOW_HEIGHT);
            break;
        case 3:
            asteroid_spawn_x = RNG::get_float(0, WINDOW_WIDTH);
            asteroid_spawn_y = -50.f;
            break;
        case 4:
            asteroid_spawn_x = RNG::get_float(0, WINDOW_WIDTH);
            asteroid_spawn_y = WINDOW_HEIGHT + 50.f;
            break;
        }
        float asteroid_move_dir = look_at_direction(_player.get_pos().x - asteroid_spawn_x, _player.get_pos().y - asteroid_spawn_y);
        _asteroids.push_back(Asteroid(asteroid_spawn_x, asteroid_spawn_y, asteroid_move_dir));
        _spawn_time -= 0.05f;
    }

    for (auto asteroid_it = _asteroids.begin(); asteroid_it != _asteroids.end(); asteroid_it++)
    {
        asteroid_it->update();
        if (asteroid_it->should_remove)
        {
            _asteroids.erase(asteroid_it);
            break;
        }
    }

    _score_text.setString("score: " + std::to_string(_player.score));
}


void PlayState::render(sf::RenderWindow& window)
{
    window.clear();

    _player.render(window);

    for (auto& bullet : _bullets)
        bullet.render(window);

    for (auto& asteroid : _asteroids)
        asteroid.render(window);

    window.draw(_score_text);
    
    window.display();
}


Player& PlayState::get_player()
{
    return _player;
}
