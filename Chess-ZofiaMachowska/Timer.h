#include <iostream>
#include <chrono>
#include <thread>

class Timer {
private:
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::duration<int> initial_duration;
    bool is_running;

public:
    std::chrono::duration<int> remaining_time;

    Timer();
    void start();
    void stop();
    void resume();
    void reset();
    void displayTime();
    bool isRunning();
};
