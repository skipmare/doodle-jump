#include "Stopwatch.h"

// Private constructor
Stopwatch::Stopwatch() : running(false), deltaTime(0.0) {}

// Start the stopwatch
void Stopwatch::start() {
    running = true;
    startTime = std::chrono::high_resolution_clock::now();
    previousTime = startTime;
}

// Stop the stopwatch
void Stopwatch::stop() {
    running = false;
}

// Get the elapsed time in seconds
double Stopwatch::getElapsedTime() const {
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(now - startTime).count();
    }
    return 0.0;
}

// Update the stopwatch and return the delta time
double Stopwatch::tick() {
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<double>(now - previousTime).count();
        previousTime = now;
        return deltaTime;
    }
    return 0.0;
}

// Get the delta time in seconds
double Stopwatch::getDeltaTime() const {
    return deltaTime;
}