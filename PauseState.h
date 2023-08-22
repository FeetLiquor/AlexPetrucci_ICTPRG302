#include "State.h"


class PauseState : public State
{
public:
    PauseState();
    void handle_events(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text _title_text;
};