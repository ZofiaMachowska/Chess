#pragma once
#include <SFML/Graphics.hpp>
#include "AppState.h"
#include "UIOptions.h"
#include "Application.h"

/**
 * @class OptionsState
 * @brief Represents the options state of the application.
 */
class OptionsState : public AppState {
private:
    UIOptions uiOptions; /**< Controller for the options UI. */

public:
    /**
     * @brief Constructor for OptionsState.
     */
    OptionsState();

    /**
     * @brief Destructor for OptionsState.
     */
    ~OptionsState();

    /**
     * @brief Handles SFML events for the options state.
     *
     * @param event The SFML event to handle.
     * @param window The SFML window where the event occurred.
     */
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;

    /**
     * @brief Renders the options state.
     *
     * @param window The SFML window to render.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Initializes the options state.
     */
    void initialize() override;
};
