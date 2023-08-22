#include "EndState.h"

#include "ResourceManager.h"
#include "config.h"
#include "PlayState.h"
#include <fstream>


EndState::EndState()
{
    _game_over_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));
    _score_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));
    _high_score_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));

    _game_over_text.setCharacterSize(32);
    _score_text.setCharacterSize(32);
    _high_score_text.setCharacterSize(32);

    _game_over_text.setString("Game Over");
}


void EndState::handle_events(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        delete State::play;
        State::play = new PlayState;
        State::current = State::play;
        _initialized = false;
    }
}


void EndState::update()
{
    if (!_initialized)
    {
        PlayState* play_state = dynamic_cast<PlayState*>(State::play);
        if (play_state)
            _score_text.setString("Your score was: " + std::to_string(play_state->get_player().score));

        _game_over_text.setPosition((WINDOW_WIDTH - _game_over_text.getGlobalBounds().width) / 2,
            (WINDOW_HEIGHT - _game_over_text.getGlobalBounds().height - _score_text.getGlobalBounds().height - 10) / 2);
        _score_text.setPosition((WINDOW_WIDTH - _score_text.getGlobalBounds().width) / 2,
            (WINDOW_HEIGHT - _score_text.getGlobalBounds().height + _game_over_text.getGlobalBounds().height + 10) / 2);

        std::fstream high_score_file("scores.txt");
        int high_score;
        high_score_file >> high_score;
        high_score_file.close();
        if (play_state->get_player().score > high_score)
        {
            high_score = play_state->get_player().score;
            high_score_file.open("scores.txt", std::ios::out);
            high_score_file << high_score;
        }
        high_score_file.close();
        _high_score_text.setString("Highscore: " + std::to_string(high_score));

        _high_score_text.setPosition((WINDOW_WIDTH - _high_score_text.getGlobalBounds().width) / 2,
            WINDOW_HEIGHT - _high_score_text.getGlobalBounds().height * 2);

        _initialized = true;
    }
}


void EndState::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_game_over_text);
    window.draw(_score_text);
    window.draw(_high_score_text);
    window.display();
}
