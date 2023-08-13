#include "Timer.h"

Timer::Timer() : initialDuration(std::chrono::minutes(5)), remainingTime(initialDuration), isRunning(false)
{
}

void  Timer::setTimerOverCallback(std::function<void()> callback) {
    timerOverCallback = std::move(callback);
}

void Timer::timeOver() {
    if (timerOverCallback) {
        timerOverCallback();
    }
}

void Timer::start() {
    if (!isRunning) {
        startTime = std::chrono::system_clock::now();
        isRunning = true;
        isTerminated = false;
        timerThread = std::thread([this]() {
            while (!isTerminated) {
                if (isRunning) {
                    elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTime);
                    remainingTime = initialDuration - elapsedTime;
                    if (remainingTime.count() <= 0) {
                        timeOver();
                    }
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            });

        std::cout << "Timer started." << std::endl;
    }
    else {
        std::cout << "Timer is already running." << std::endl;
    }
}

void Timer::stop() {
    if (isRunning) {
        isRunning = false;
        isTerminated = true;
        timerThread.join();
        std::cout << "Timer stopped." << std::endl;
    }
    else {
        std::cout << "Timer is not running." << std::endl;
    }
}

void Timer::resume() {
    if (!isRunning) {
        timeAtStop = remainingTime;
        startTime = std::chrono::system_clock::now();
        isRunning = true;
        isTerminated = false;
        timerThread = std::thread([this]() {
            while (!isTerminated) {
                if (isRunning) {
                    elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTime);
                    remainingTime = timeAtStop - elapsedTime;
                    if (remainingTime.count() <= 0) {
                        timeOver();
                    }
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            });
        std::cout << "Timer resumed." << std::endl;
    }
    else {
        std::cout << "Timer is already running." << std::endl;
    }
}

void Timer::reset() {
    remainingTime = initialDuration;
    std::cout << "Timer reset." << std::endl;
}

std::pair<int, int> Timer::getTime() {
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(remainingTime).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(remainingTime).count() % 60;
    return std::make_pair(minutes, seconds);
}
