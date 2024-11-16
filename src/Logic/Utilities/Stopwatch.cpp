#include "Stopwatch.h"

// Starts the stopwatch

void Stopwatch::start() {
    startTime = std::chrono::high_resolution_clock::now();
    previousTime = startTime;
    running = true;
}

// Stops the stopwatch

void Stopwatch::stop() {
    running = false;
}

// Returns the elapsed time in seconds

double Stopwatch::getElapsedTime() const {
    if (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(currentTime - startTime).count();
    }
    return 0.0;
}

// Updates the stopwatch

void Stopwatch::tick() {
    if (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = currentTime - previousTime;
        previousTime = currentTime;
    }
}

// Returns the delta time in seconds

double Stopwatch::getDeltaTime() const {
    return deltaTime.count();
}