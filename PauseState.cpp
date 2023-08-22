#include "PauseState.h"

#include "ResourceManager.h"
#include "config.h"


PauseState::PauseState()
{
    _title_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));
    _title_text.setString("Game Paused");
    _title_text.setCharacterSize(32);
}


void PauseState::handle_events(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
            State::current = State::play;
    }
}


void PauseState::update()
{
}


void PauseState::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_title_text);
    window.display();
}