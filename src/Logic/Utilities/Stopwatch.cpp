#include "Stopwatch.h"

// Private constructor
/**
 * @brief Private constructor for the Stopwatch class.
 *
 * Initializes the stopwatch to a stopped state and sets the initial delta time to 0.
 */
Stopwatch::Stopwatch() : running(false), deltaTime(0.0) {}

// Start the stopwatch
/**
 * @brief Starts the stopwatch.
 *
 * Begins tracking time by recording the current time as the start time. The stopwatch is marked as running.
 */
void Stopwatch::start() {
    running = true;
    startTime = std::chrono::high_resolution_clock::now();
    previousTime = startTime;
}

// Stop the stopwatch
/**
 * @brief Stops the stopwatch.
 *
 * Stops the stopwatch and prevents any further time tracking.
 */
void Stopwatch::stop() {
    running = false;
}

/**
 * @brief Gets the elapsed time in seconds.
 *
 * If the stopwatch is running, calculates and returns the time elapsed since the stopwatch was started.
 *
 * @return The elapsed time in seconds. Returns 0 if the stopwatch is not running.
 */
float Stopwatch::getElapsedTime() const {
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(now - startTime).count();
    }
    return 0.0;
}

/**
 * @brief Updates the stopwatch and returns the delta time in seconds.
 *
 * Calculates the time elapsed since the last tick and returns it as the delta time. If the stopwatch is
 * not running, returns 0.
 *
 * @return The delta time in seconds. Returns 0 if the stopwatch is not running.
 */
float Stopwatch::tick() {
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<double>(now - previousTime).count();
        previousTime = now;
        return deltaTime;
    }
    return 0.0;
}

/**
 * @brief Gets the delta time in seconds.
 *
 * Returns the time difference between the current tick and the previous tick in seconds.
 *
 * @return The delta time in seconds.
 */
float Stopwatch::getDeltaTime() const {
    return deltaTime;
}
