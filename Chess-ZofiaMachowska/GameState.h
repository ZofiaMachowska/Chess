#pragma once
#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "UIBoardController.h"
#include "AIController.h"
#include "AppState.h"
#include "Application.h"
#include "SavingGameController.h"

/**
 * @class GameState
 * @brief Represents the main gameplay state of the application.
 *
 */
class GameState : public AppState {
private:
    BoardController board;       /**< The main game board controller. */
    UIBoardController uiController; /**< Controller for the game's user interface. */
    sf::Event event;             /**< Stores the latest event for processing. */

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
     * @brief Controller to handle saving game state.
     */
    static SavingGameController saveController;

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
     * @brief Initializes or resets game-specific elements for the game state.
     */
    void initialize() override;
};
