#pragma once
#include <SFML/Graphics.hpp>

class AppState {
public:
    virtual void handleEvent(sf::Event event, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void setTextures() = 0;
};