#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

/**
 * @brief A class that manages and measures time intervals.
 *
 * This timer can be started, stopped, and reset. It also allows users to register a callback
 * that is invoked when the timer's time has been over.
 */
class Timer {
private:
    /**
     * @brief Invoked when the timer's time runs out.
     *
     * This function triggers the `timerOverCallback`.
     */
    void timeOver();

    /**
     * @brief A thread for the timer.
     */
    std::thread timerThread;

    /**
     * @brief Flag indicating if the timer's thread is terminated.
     */
    std::atomic<bool> isTerminated;

    /**
     * @brief Stores the point in time when the timer was started.
     */
    std::chrono::time_point<std::chrono::system_clock> startTime;

public:
    /**
     * @brief Constructs the Timer object.
     */
    Timer();

    /**
     * @brief Destroys the Timer object.
     */
    ~Timer();

    /**
     * @brief Starts the timer.
     */
    void start();

    /**
     * @brief Stops the timer. It can later be resumed or reset.
     */
    void stop();

    /**
     * @brief Resumes the timer from where it was stopped.
     */
    void resume();

    /**
     * @brief Resets the timer to its initial duration.
     */
    void reset();

    /**
     * @brief Starts the timer thread.
     */
    void startThread();

    /**
     * @brief Sets a callback function that will be invoked when the timer runs out.
     *
     * @param callback The function to be called when the timer expires.
     */
    void setTimerOverCallback(std::function<void()> callback);

    /**
     * @brief Retrieves the elapsed time since the timer was started.
     *
     * @return A pair of integers representing minutes and seconds respectively.
     */
    std::pair<int, int> getTime();

    /**
     * @brief The initial duration set for the timer.
     */
    std::chrono::duration<int> initialDuration;

    /**
     * @brief The amount of time that has passed since the timer was last started.
     */
    std::chrono::duration<int> elapsedTime;

    /**
     * @brief The amount of time at which the timer was stopped.
     */
    std::chrono::duration<int> timeAtStop;

    /**
     * @brief The callback function that is invoked when the timer runs out.
     */
    std::function<void()> timerOverCallback;

    /**
     * @brief The amount of time remaining on the timer.
     */
    std::chrono::duration<int> remainingTime;

    /**
     * @brief Indicates if the timer is currently running.
     */
    bool isRunning;
};
