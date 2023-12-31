#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Button.h"

/**
 * @brief Represents the user interface (UI) controller for the game's main menu.
 * This class is responsible for rendering and handling the main menu options.
 */
class UIMenu
{
public:
    /**
     * @brief Constructs the UIMenuController, setting up initial state.
     */
    UIMenu();

    /**
     * @brief Destroys the UIMenuController.
     */
    ~UIMenu();

    /**
     * @brief Redraws the main menu with updated visuals.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void redrawWindow(sf::RenderWindow& window);

    /**
     * @brief Initializes the visuals for the main menu.
     */
    void initializeVisuals();

    /**
     * @brief Handles button press events for the main menu.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void handleButtonPress(sf::RenderWindow& window);

    /**
     * @brief Sets a callback to be triggered when the user selects the "New Game" option.
     *
     * @param callback A function to be called upon the "New Game" event.
     */
    void setNewGameCallback(std::function<void()> callback);

    /**
     * @brief Sets a callback to be triggered when the user selects the "Load Game" option.
     *
     * @param callback A function to be called upon the "Load Game" event.
     */
    void setLoadGameCallback(std::function<void()> callback);

    /**
     * @brief Sets a callback to be triggered when the user selects the "Options" option.
     *
     * @param callback A function to be called upon the "Options" event.
     */
    void setOptionsCallback(std::function<void()> callback);

private:
    sf::Text titleText; ///< SFML Text object representing the title of the game.
    sf::Font font; ///< Font used for rendering text in the menu.
    std::function<void()> newGameCallback; ///< Callback function for the "New Game" action.
    std::function<void()> loadGameCallback; ///< Callback function for the "Load Game" action.
    std::function<void()> optionsCallback; ///< Callback function for the "Options" action.
    Button* newGameButton; ///< Pointer to the button for starting a new game.
    Button* loadGameButton; ///< Pointer to the button for loading a saved game.
    Button* optionsButton; ///< Pointer to the button for accessing the game options.
    Button* exitButton; ///< Pointer to the button for exiting the game.
};