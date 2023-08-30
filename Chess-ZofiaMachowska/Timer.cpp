#include "Timer.h"
#include <iostream>

Timer::Timer()
    : initialDuration(std::chrono::minutes(5)),
    remainingTime(std::chrono::duration_cast<std::chrono::seconds>(initialDuration)),
    isRunning(false),
    isTerminated(false) {}

Timer::~Timer() {
    if (timerThread.joinable()) {
        isTerminated = true;
        timerThread.join();
    }
}

void Timer::setTimerOverCallback(std::function<void()> callback) {
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
        lastUpdateTime = std::chrono::system_clock::now();
        while (!isTerminated) {
            if (isRunning) {
                auto now = std::chrono::system_clock::now();
                auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdateTime);
                lastUpdateTime = now;
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
    lastUpdateTime = startTime;
    isRunning = true;
    startThread();
}

void Timer::stop() {
    if (!isRunning) {
        return;
    }
    isRunning = false;
    isTerminated = true;
    if (timerThread.joinable()) {
        timerThread.join();
    }
}

void Timer::resume() {
    if (isRunning) {
        return;
    }
    isRunning = true;
    lastUpdateTime = std::chrono::system_clock::now();
    startThread();
}

void Timer::reset() {
    remainingTime = std::chrono::duration_cast<std::chrono::seconds>(initialDuration);
}

std::pair<int, int> Timer::getTime() {
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(remainingTime).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(remainingTime).count() % 60;
    return std::make_pair(minutes, seconds);
}

int Timer::getInitialDuration() const {
    return std::chrono::duration_cast<std::chrono::minutes>(initialDuration).count();
}

int Timer::getRemainingTime() const {
    return std::chrono::duration_cast<std::chrono::seconds>(remainingTime).count();
}

bool Timer::getIsRunning() const {
    return isRunning;
}

void Timer::setInitialDuration(std::chrono::minutes initDur) {
    initialDuration = initDur;
}

void Timer::setRemainingTime(std::chrono::seconds remTime) {
    remainingTime = remTime;
}

void Timer::setIsRunning(bool running)
{
    isRunning = running;
}

