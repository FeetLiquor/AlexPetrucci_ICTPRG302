#pragma once

#include "State.h"


class EndState : public State
{
public:
    EndState();
    void handle_events(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text _game_over_text;
    sf::Text _score_text;
    sf::Text _high_score_text;
    bool _initialized = false;
};