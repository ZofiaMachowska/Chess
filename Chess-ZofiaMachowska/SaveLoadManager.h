#pragma once
#include <fstream>
#include <iostream>
#include <json\json.h>
#include "Player.h"
#include "Game.h"
#include "ChessPiece.h"
#include "chessStructures.h"

/**
 * @brief Manages game saving and loading functionalities.
 *
 * This controller provides mechanisms to save and load games, utilizing the JSON format.
 */
class SaveLoadManager
{
public:
    bool shouldLoadAGame();
    void setFlagToLoadGame(int flag);
    SaveLoadManager();
    /**
     * @brief Destroys the SavingGameController object.
     */
    ~SaveLoadManager();
    GameSaveLoad getGameToLoad();

    /**
     * @brief Adds a new game to the game history.
     *
     * @param board The current state of the chessboard.
     * @param players Vector containing pointers to player objects.
     * @param gameOver Indicates if the game is over or not.
     */
    void addNewGameToHistory(Game& game);

    /**
     * @brief Saves all games from the game history to a file.
     */
    void saveGameToFile();

    /**
     * @brief Loads all games from a file to the game history.
     */
    void loadGamesFromFile();

    /**
     * @brief Sets the callback function to be triggered after a new game is saved.
     *
     * @param callback Function to be called after a new game is saved.
     */
    void setSaveNewGameCallback(std::function<void()> callback);

    /**
     * @brief Returns a vector containing all saved games.
     *
     * @return Vector of Game objects.
     */
    std::vector<GameSaveLoad> getGames();

    /**
     * @brief Vector storing all the saved games.
     */
    std::vector<GameSaveLoad> games;

    /**
     * @brief Callback function triggered after a new game is saved.
     */
    std::function<void()> savedNewGameCallback;

private:
    /**
     * @brief Constructs a Player object from a given JSON value.
     *
     * @param jsonPlayer JSON representation of a player.
     * @return Pointer to a Player object.
     */
    Player createPlayerFromJson(const Json::Value& jsonPlayer);
    int gameToLoad = -1;

    ChessPiece* createChessPieceFromTypeAndColor(std::string type, std::string color, int row, int col);

    /**
     * @brief Constructs a Timer object from a given JSON value.
     *
     * @param jsonTimer JSON representation of a timer.
     * @return Pointer to a Timer object.
     */
    Timer* createTimerFromJson(const Json::Value& jsonTimer);

    /**
     * @brief Converts a Player object to its JSON representation.
     *
     * @param player Pointer to the Player object.
     * @return JSON representation of the player.
     */
    Json::Value playerToJson(Player player) const;
    /**
     * @brief Converts a Timer object to its JSON representation.
     *
     * @param time Pointer to the Timer object.
     * @return JSON representation of the timer.
     */
    Json::Value timerToJson(Timer* time) const;

    /**
     * @brief Maximum number of games that can be stored in the history.
     */
    const int MAX_GAME_HISTORY = 6;

    /**
     * @brief Name of the file where game data is saved and loaded from.
     */
    const std::string FILE_NAME = "stan_gry.json";

};

