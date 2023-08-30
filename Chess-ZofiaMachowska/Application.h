#pragma once
#include <SFML/Graphics.hpp>
#include "UIBoard.h"
#include "AI.h"
#include "UIMenu.h"
#include "AppState.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoadingState.h"
#include "OptionsState.h"
#include "SaveLoadManager.h"

/**
 * @brief Main class of the application. Manages the game loop and holds references to main components of the game.
 */
class Application {
private:
    /**
     * @brief AI player's options.
     */
   // static Options aiPlayerOptions;

    /**
     * @brief Pointer to the current application state.
     */
    static std::unique_ptr<AppState> currentState;

    /**
     * @brief Static member holding the index of the game to be loaded.
     */
    static int gameToLoad;

    /**
     * @brief Main window of the application.
     */
    sf::RenderWindow window;
public:
    /**
     * @brief Construct a new Application object.
     */
    Application();

    /**
     * @brief Destroy the Application.
     */
    ~Application();

    /**
     * @brief Change the current application state.
     *
     * @param newState pointer to the new application state.
     */
    static void changeAppState(std::unique_ptr<AppState> newState);

    /**
     * @brief Set the options choice for the AI player.
     *
     * @param optionsChoice The desired AI player options.
     */
   // static void setOptionsChoice(Options optionsChoice);


    /**
     * @brief Start the application's main loop.
     */
    void run();
    static SaveLoadManager saveLoadManager;

    /**
     * @brief Get the AI player options value.
     *
     * @return Options currently set for the AI player.
     */
    //static Options getAiPlayerOptionsValue();
};
