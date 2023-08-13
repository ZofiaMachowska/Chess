#include "Timer.h"

Timer::Timer() : initialDuration(std::chrono::minutes(5)), remainingTime(initialDuration), isRunning(false)
{
}

Timer::~Timer()
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

void Timer::startThread() {
    isTerminated = false;
    timerThread = std::thread([this]() {
        while (!isTerminated) {
            if (isRunning) {
                elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTime);
                remainingTime -= elapsedTime;
                if (remainingTime.count() <= 0) {
                    timeOver();
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        });
}

void Timer::start() {
    if (isRunning) {
        return;
    }
    startTime = std::chrono::system_clock::now();
    isRunning = true;
    startThread();
}

void Timer::stop() {
    if (!isRunning) {
        return;
    }
    isRunning = false;
    isTerminated = true;
    timerThread.join();
}

void Timer::resume() {
    if (isRunning) {
        return;
    }
    timeAtStop = remainingTime;
    startTime = std::chrono::system_clock::now();
    isRunning = true;
    startThread();
}

void Timer::reset() {
    remainingTime = initialDuration;
}

std::pair<int, int> Timer::getTime() {
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(remainingTime).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(remainingTime).count() % 60;
    return std::make_pair(minutes, seconds);
}
