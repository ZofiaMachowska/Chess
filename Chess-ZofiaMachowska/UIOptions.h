#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Checkbox.h"
#include <iostream>
#include "Button.h"
#include "chessStructures.h"
#include "aiOptions.h"

/**
 * @brief Represents the user interface (UI) controller for the game's options menu.
 * This class is responsible for rendering and handling AI choices.
 */
class UIOptions
{
public:
    /**
     * @brief Constructs the UIOptions, setting up the initial state.
     */
    UIOptions();

    /**
     * @brief Destroys the UIOptions.
     */
    ~UIOptions();

    /**
     * @brief Redraws the options menu with updated visuals.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void redrawWindow(sf::RenderWindow& window);

    /**
     * @brief Initializes the visuals (like fonts, checkboxes, buttons, etc.) for the options menu.
     */
    void initializeVisuals();

    /**
     * @brief Handles button press and checkbox interactions in the options menu.
     *
     * @param mousePosition Position of the mouse when the event occurred.
     */
    void handleButtonPress(const sf::Vector2i& mousePosition);

    /**
     * @brief Sets a callback to be triggered when the user chooses to return from the options menu.
     *
     * @param callback A function to be called upon returning from the options menu.
     */
    void setOptionsReturnCallback(std::function<void()> callback);

    /**
     * @brief Sets a callback to be triggered when AI options change.
     *
     * @param callback A function to be called when AI options are modified.
     */
    void setOptionsAiChangesCallback(std::function<void()> callback);

    /**
     * @brief Sets the last known AI choices in the checkboxes.
     *
     * @param lastOptionsValue A structure containing previous choices of AI settings.
     */
    void setCheckboxLastValue(aiOptions lastOptionsValue);

    aiOptions aiOptionsChoice; ///< Current AI options settings.

private:
    /**
     * @brief Processes the current state of checkboxes to determine the AI options.
     */
    void setAiOptionsChoice();

    std::function<void()> optionsReturnCallback; ///< Callback function for the return action.
    std::function<void()> aiChangesCallback; ///< Callback function for AI changes.
    Button* backButton; ///< Pointer to the button for returning from options menu.
    sf::Text player1AIText; ///< SFML Text object representing AI settings for Player 1.
    sf::Text player2AIText; ///< SFML Text object representing AI settings for Player 2.
    sf::Font font; ///< Font used for rendering text in the options menu.
    Checkbox* player1CheckBox; ///< Checkbox allowing selection of AI for Player 1.
    Checkbox* player2CheckBox; ///< Checkbox allowing selection of AI for Player 2.
};

