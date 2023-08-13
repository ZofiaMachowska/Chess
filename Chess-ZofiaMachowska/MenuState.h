#pragma once
#include "UIMenuController.h"
#include "AppState.h"
#include "Application.h"
#include "GameState.h"

/**
 * @class MenuState
 * @brief Represents the menu state of the application.
 */
class MenuState : public AppState {
private:
    UIMenuController uiMenuController; /**< Controller for the menu UI. */

public:
    /**
     * @brief Constructor for MenuState.
     */
    MenuState();

    /**
     * @brief Destructor for MenuState.
     */
    ~MenuState();

    /**
     * @brief Handles SFML events for the menu state.
     *
     * @param event The SFML event to handle.
     * @param window The SFML window where the event occurred.
     */
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;

    /**
     * @brief Renders the menu state.
     *
     * @param window The SFML window to render to.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Initializes the menu state.
     */
    void initialize() override;
};
