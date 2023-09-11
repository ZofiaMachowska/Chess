#pragma once
#include <chrono>
#include <thread>
#include <functional>

/**
 * @class Timer
 * @brief Represents a timer for tracking time.
 */
class Timer {
public:
    /**
     * @brief Default constructor for Timer.
     */
    Timer();

    /**
     * @brief Destructor for Timer.
     */
    ~Timer();

    /**
     * @brief Set a callback function to be called when the timer is over.
     * @param callback The callback function.
     */
    void setTimerOverCallback(std::function<void()> callback);

    /**
     * @brief Start the timer.
     */
    void start();

    /**
     * @brief Stop the timer.
     */
    void stop();

    /**
     * @brief Resume the timer.
     */
    void resume();

    /**
     * @brief Reset the timer.
     */
    void reset();

    /**
     * @brief Get the remaining time on the timer.
     * @return A pair of integers representing minutes and seconds.
     */
    std::pair<int, int> getTime();

    /**
     * @brief Check if the timer is currently running.
     * @return True if the timer is running, false otherwise.
     */
    bool getIsRunning() const;

    /**
     * @brief Get the remaining time on the timer in seconds.
     * @return The remaining time in seconds.
     */
    int getRemainingTime() const;

    /**
     * @brief Get the initial duration of the timer in minutes.
     * @return The initial duration in minutes.
     */
    int getInitialDuration() const;

    /**
     * @brief Set the initial duration of the timer.
     * @param initDur The initial duration in minutes.
     */
    void setInitialDuration(std::chrono::minutes initDur);

    /**
     * @brief Set the remaining time on the timer.
     * @param remTime The remaining time in seconds.
     */
    void setRemainingTime(std::chrono::seconds remTime);

    /**
     * @brief Set the running status of the timer.
     * @param running True to indicate the timer is running, false otherwise.
     */
    void setIsRunning(bool running);

private:
    /**
     * @brief Handle the time over event.
     */
    void timeOver();

    /**
     * @brief Start the timer thread.
     */
    void startThread();

    std::chrono::minutes initialDuration; /**< The initial duration of the timer in minutes. */
    std::chrono::seconds remainingTime; /**< The remaining time on the timer in seconds. */
    std::chrono::system_clock::time_point startTime; /**< The timestamp when the timer was started. */
    std::chrono::system_clock::time_point lastUpdateTime; /**< The timestamp of the last timer update. */
    std::thread timerThread; /**< The thread responsible for running the timer. */
    std::function<void()> timerOverCallback; /**< The callback function called when the timer is over. */

    bool isRunning; /**< Flag indicating whether the timer is currently running. */
    bool isTerminated; /**< Flag indicating whether the timer has been terminated. */

};
