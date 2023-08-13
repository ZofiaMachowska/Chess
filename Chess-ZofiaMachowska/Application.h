#pragma once
#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "UIBoardController.h"
#include "AIController.h"
#include "UIMenuController.h"
#include "AppState.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoadingState.h"
#include "OptionsState.h"
#include "chessStructures.h"

/**
 * @brief Main class of the application. Manages the game loop and holds references to main components of the game.
 */
class Application {
public:
    /**
     * @brief Construct a new Application object.
     */
    Application();

    /**
     * @brief Destroy the Application object and free resources.
     */
    ~Application();

    /**
     * @brief Change the current application state.
     *
     * @param newState Unique pointer to the new application state.
     */
    static void changeAppState(std::unique_ptr<AppState> newState);

    /**
     * @brief Set the options choice for the AI player.
     *
     * @param optionsChoice The desired AI player options.
     */
    static void setOptionsChoice(Options optionsChoice);

    /**
     * @brief Set the index of the game to load.
     *
     * @param index Index of the saved game to be loaded.
     */
    static void setGameIndexToLoad(int index);

    /**
     * @brief Set the list of saved games.
     *
     * @param games Vector containing saved game data.
     */
    static void setSavedGames(std::vector<Game> games);

    /**
     * @brief Start the application's main loop.
     */
    void run();

    /**
     * @brief Get the AI player options value.
     *
     * @return Options currently set for the AI player.
     */
    static Options getAiPlayerOptionsValue();

    /**
     * @brief Retrieve the game data to be loaded.
     *
     * @return Game data for the game to be loaded.
     */
    static Game getGameToLoad();

    /**
     * @brief Get the list of saved games.
     *
     * @return Vector containing saved game data.
     */
    static std::vector<Game> getSavedGamesValues();

    /**
     * @brief Static member holding the index of the game to be loaded.
     */
    static int gameToLoad;

private:
    /**
     * @brief AI player's options.
     */
    static Options aiPlayerOptions;

    /**
     * @brief List of saved games.
     */
    static std::vector<Game> games;

    /**
     * @brief Unique pointer to the current application state.
     */
    static std::unique_ptr<AppState> currentState;

    /**
     * @brief Main window of the application.
     */
    sf::RenderWindow window;
};
