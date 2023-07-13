#pragma once
#include <SFML/Graphics.hpp>
#include "AppState.h"

class OptionsState : public AppState {
public:
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setTextures() override;
};
