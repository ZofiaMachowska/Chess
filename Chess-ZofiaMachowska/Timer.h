#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

class Timer {
private:
    void timeOver();
    std::thread timerThread;
    std::atomic<bool> isTerminated;
    std::chrono::time_point<std::chrono::system_clock> startTime;

public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void resume();
    void reset();
    void startThread();
    void setTimerOverCallback(std::function<void()> callback);
    std::pair<int, int> getTime();

    std::chrono::duration<int> initialDuration;
    std::chrono::duration<int> elapsedTime;
    std::chrono::duration<int> timeAtStop;
    std::function<void()> timerOverCallback;
    std::chrono::duration<int> remainingTime;
    bool isRunning;
};
