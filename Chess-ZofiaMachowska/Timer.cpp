#include "Timer.h"

Timer::Timer() : initial_duration(std::chrono::minutes(5)), remaining_time(initial_duration), is_running(false)
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
    if (!is_running) {
        start_time = std::chrono::system_clock::now();
        is_running = true;
        is_terminated = false;
        timer_thread = std::thread([this]() {
            while (!is_terminated) {
                if (is_running) {
                    elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time);
                    remaining_time = initial_duration - elapsed_time;
                    if (remaining_time.count() <= 0) {
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
    if (is_running) {
        is_running = false;
        is_terminated = true;
        timer_thread.join();
        std::cout << "Timer stopped." << std::endl;
    }
    else {
        std::cout << "Timer is not running." << std::endl;
    }
}

void Timer::resume() {
    if (!is_running) {
        timeAtStop = remaining_time;
        start_time = std::chrono::system_clock::now();
        is_running = true;
        is_terminated = false;
        timer_thread = std::thread([this]() {
            while (!is_terminated) {
                if (is_running) {
                    elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time);
                    remaining_time = timeAtStop - elapsed_time;
                    if (remaining_time.count() <= 0) {
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
    if (!is_running) {
        remaining_time = initial_duration;
        std::cout << "Timer reset." << std::endl;
    }
    else {
        std::cout << "Stop the timer before resetting." << std::endl;
    }
}

std::pair<int, int> Timer::getTime() {
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(remaining_time).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(remaining_time).count() % 60;
    return std::make_pair(minutes, seconds);
}
