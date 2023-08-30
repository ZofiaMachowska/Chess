#pragma once
#include <SFML/Graphics.hpp>
#include "UIBoard.h"
#include "AppState.h"
#include "Application.h"
#include "Game.h"

/**
 * @class GameState
 * @brief Represents the main gameplay state of the application.
 *
 */
class GameState : public AppState {
private:
    UIBoard uiBoard; /**< Controller for the game's user interface. */
    sf::Event event;             /**< Stores the latest event. */
    Game game;

public:
    /**
     * @brief Default constructor for GameState.
     */
    GameState();

    /**
     * @brief Destructor for GameState.
     */
    ~GameState();

    /**
     * @brief Handle SFML events for the game state.
     *
     * @param event The SFML event to handle.
     * @param window Reference to the SFML window where the event occurred.
     */
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;

    /**
     * @brief Renders the game state to the provided SFML window.
     *
     * @param window Reference to the SFML window to render to.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Initializes or resets game elements for the game state.
     */
    void initialize() override;
};
