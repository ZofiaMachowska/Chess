#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

/**
 * @class AppState
 * 
 * @brief Abstract base class representing a state in an application.
 */
class AppState {
public:
    /**
     * @brief Handle SFML events like mouse input.
     *
     * @param event The event to handle.
     * @param window Reference to the window where the event occurred.
     */
    virtual void handleEvent(sf::Event event, sf::RenderWindow& window) = 0;

    /**
     * @brief Render graphics to the provided window.
     *
     * @param window Reference to the window to render to.
     */
    virtual void render(sf::RenderWindow& window) = 0;

    /**
     * @brief Initialize or reset state elements.
     */
    virtual void initialize() = 0;
};
