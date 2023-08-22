#pragma once

#include "State.h"


class StartState : public State
{
public:
    StartState();
    void handle_events(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

protected:
    sf::Text _title_text;
};