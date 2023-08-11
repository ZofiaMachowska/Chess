#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

class Timer {
private:

    void timeOver();

public:
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::duration<int> initial_duration;
    bool is_running;
    std::atomic<bool> is_terminated;
    std::thread timer_thread;
    std::chrono::duration<int> elapsed_time;
    std::chrono::duration<int> timeAtStop;
    std::function<void()> timerOverCallback;
    std::chrono::duration<int> remaining_time;
    void setTimerOverCallback(std::function<void()> callback);

    Timer();
    void start();
    void stop();
    void resume();
    void reset();
    std::pair<int, int> getTime();
};
