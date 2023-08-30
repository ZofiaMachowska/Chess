#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include <iostream>
#include "Button.h"
#include "chessStructures.h"

/**
 * @brief Represents the user interface (UI) controller for the game's loading screen.
 * This class is responsible for rendering and handling saved game listings, allowing users to load a previous game.
 */
class UILoading
{
public:
    /**
     * @brief Constructs the UILoadingController, setting up initial state.
     */
    UILoading();

    /**
     * @brief Destroys the UILoadingController.
     */
    ~UILoading();

    /**
     * @brief Redraws the loading screen with updated visuals.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void redrawWindow(sf::RenderWindow& window);

    /**
     * @brief Initializes the visuals for the loading screen.
     */
    void initializeVisuals();

    /**
     * @brief Handles button press events for the loading screen.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void handleButtonPress(sf::RenderWindow& window);

    /**
     * @brief Sets a callback to be triggered when the user wishes to return to the main menu.
     *
     * @param callback A function to be called upon the return event.
     */
    void setReturnToMenuCallback(std::function<void()> callback);

    /**
     * @brief Sets a callback to be triggered when the user selects a game to load.
     *
     * @param callback A function to be called upon game selection.
     */
    void setLoadThisGameCallback(std::function<void()> callback);

    /**
     * @brief Updates the UI with the list of saved games available to load.
     *
     * @param games Vector containing saved game information.
     */
    void getSavedGames(std::vector<GameSaveLoad> games);

    int gameToLoadNext; ///< The index of the game that will be loaded next. Initialized to -1 to indicate no selection.

private:
    Button* backButton; ///< Pointer to the back button allowing users to return to the previous screen.
    sf::Font font; ///< Font used for rendering text.
    std::function<void()> returnToMenuCallback; ///< Callback function for the "return to menu" action.
    std::function<void()> loadThisGameCallback; ///< Callback function for the "load this game" action.
    std::vector<GameSaveLoad> gamesLoading; ///< Vector storing saved game data.
    std::vector<Button*> buttons; ///< Vector storing pointers to the UI buttons.
};
