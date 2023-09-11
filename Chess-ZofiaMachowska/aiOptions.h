#pragma once

/**
 * @class aiOptions
 * @brief Represents options for configuring AI players.
 */
class aiOptions {
private:
    bool firstPlayerAi; /**< Flag for the first player being AI-controlled. */
    bool secondPlayerAi; /**< Flag for the second player being AI-controlled. */

public:
    /**
     * @brief Default constructor.
     * Initializes AI options with default values.
     */
    aiOptions();

    /**
     * @brief Set AI control for the first player.
     * @param value True to enable AI control, false to disable.
     */
    void setFirstPlayerAi(bool value);

    /**
     * @brief Set AI control for the second player.
     * @param value True to enable AI control, false to disable.
     */
    void setSecondPlayerAi(bool value);

    /**
     * @brief Check if the first player is AI-controlled.
     * @return True if the first player is AI-controlled, false otherwise.
     */
    bool getFirstPlayerAi() const;

    /**
     * @brief Check if the second player is AI-controlled.
     * @return True if the second player is AI-controlled, false otherwise.
     */
    bool getSecondPlayerAi() const;
};
