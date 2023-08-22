#include "StartState.h"

#include "config.h"
#include "ResourceManager.h"


StartState::StartState()
{
    _title_text.setString("Space Shooter");
    _title_text.setFont(ResourceManager::get_font("OCRAEXT.TTF"));
    _title_text.setCharacterSize(32);
    _title_text.setPosition((WINDOW_WIDTH  - _title_text.getLocalBounds().width ) / 2.f,
                            (WINDOW_HEIGHT - _title_text.getLocalBounds().height) / 2.f);
}


void StartState::handle_events(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
        State::current = State::play;
}


void StartState::update()
{
}


void StartState::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_title_text);
    window.display();
}
