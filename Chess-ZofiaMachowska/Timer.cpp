#include "Timer.h"

Timer::Timer() : initial_duration(std::chrono::minutes(5)), remaining_time(initial_duration), is_running(false) {}

void Timer::start() {
    if (!is_running) {
        start_time = std::chrono::system_clock::now();
        is_running = true;
        std::cout << "Timer started." << std::endl;
    }
    else {
        std::cout << "Timer is already running." << std::endl;
    }
}

void Timer::stop() {
    if (is_running) {
        std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
        remaining_time -= std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        is_running = false;
        std::cout << "Timer stopped." << std::endl;
    }
    else {
        std::cout << "Timer is not running." << std::endl;
    }
}

void Timer::resume() {
    if (!is_running) {
        start_time = std::chrono::system_clock::now();
        is_running = true;
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

void Timer::displayTime() {
    int minutes = std::chrono::duration_cast<std::chrono::minutes>(remaining_time).count();
    int seconds = std::chrono::duration_cast<std::chrono::seconds>(remaining_time).count() % 60;
    std::cout << "Remaining time: " << minutes << " min " << seconds << " sec" << std::endl;
}

bool Timer::isRunning() {
    return is_running;
}