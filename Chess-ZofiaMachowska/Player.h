#pragma once
#include "Timer.h"

/**
 * @brief Represents a player in the game, whether human or AI.
 */
class Player {
public:
    /**
     * @brief Construct a new Player object.
     *
     * @param kolor The color of the player ("white" or "black").
     * @param isActive Determines if the player is currently active.
     * @param isAI Determines if the player is controlled by AI.
     */
    Player(const std::string& kolor, const bool isActive, const bool isAI);

    /**
     * @brief Destroy the Player object and free resources.
     */
    ~Player();

    /**
     * @brief Set the active state for the player.
     *
     * @param isActive Boolean value determining if the player is active.
     */
    void setActiveState(bool isActive);

    /**
     * @brief Set the AI status for the player.
     *
     * @param aiActive Boolean value determining if the player is an AI.
     */
    void setAiStatus(bool aiActive);

    /**
     * @brief Load options for the player.
     *
     * @param playerOption Pointer to the player options to be loaded.
     */
    void loadPlayerOptions(Player* playerOption);

    /**
     * @brief Check if the player is active.
     *
     * @return true if the player is active, false otherwise.
     */
    bool checkIsActive();

    /**
     * @brief Check if the player is controlled by AI.
     *
     * @return true if the player is an AI, false otherwise.
     */
    bool isPlayerAI();

    /**
     * @brief Get the color of the player.
     *
     * @return Player color as a string ("white" or "black").
     */
    std::string getColor() const;

    /**
     * @brief Pointer to the timer associated with the player.
     */
    Timer* timer;

private:
    /**
     * @brief The color of the player ("white" or "black").
     */
    std::string color;

    /**
     * @brief Boolean determining if the player is currently active.
     */
    bool isActive;

    /**
     * @brief Boolean determining if the player is controlled by AI.
     */
    bool isAI;
};