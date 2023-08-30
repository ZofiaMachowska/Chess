#pragma once
#include <chrono>
#include <thread>
#include <functional>

class Timer {
public:
    Timer();
    ~Timer();

    void setTimerOverCallback(std::function<void()> callback);
    void start();
    void stop();
    void resume();
    void reset();
    std::pair<int, int> getTime();

    bool getIsRunning() const;
    int getRemainingTime() const;
    int getInitialDuration() const;

    void setInitialDuration(std::chrono::minutes initDur);
    void setRemainingTime(std::chrono::seconds remTime);
    void setIsRunning(bool running);

private:
    void timeOver();
    void startThread();

    std::chrono::minutes initialDuration;
    std::chrono::seconds remainingTime;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point lastUpdateTime;
    std::thread timerThread;
    std::function<void()> timerOverCallback;

    bool isRunning;
    bool isTerminated;
};
