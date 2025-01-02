#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

/**
 * @class Stopwatch
 * @brief A singleton class to measure elapsed time and delta time.
 *
 * The Stopwatch class provides functionality to measure elapsed time and track time deltas.
 * It supports starting, stopping, and updating the stopwatch, as well as retrieving elapsed time
 * and delta time between ticks. The class follows the singleton pattern, ensuring that only
 * one instance of the stopwatch is used.
 */
class Stopwatch {
public:
    /**
     * @brief Gets the instance of the Stopwatch class.
     *
     * This static method ensures that only one instance of the Stopwatch class exists
     * throughout the lifetime of the program. It follows the singleton design pattern.
     *
     * @return A reference to the singleton Stopwatch instance.
     */
    static Stopwatch& getInstance() {
        static Stopwatch instance;
        return instance;
    }

    /**
     * @brief Starts the stopwatch.
     *
     * Begins tracking time by recording the current time as the start time.
     * The stopwatch is marked as running.
     */
    void start();

    /**
     * @brief Stops the stopwatch.
     *
     * Stops the stopwatch and prevents further time tracking.
     */
    void stop();

    /**
     * @brief Gets the elapsed time in seconds.
     *
     * If the stopwatch is running, this method calculates and returns the time elapsed
     * since the stopwatch was started.
     *
     * @return The elapsed time in seconds. Returns 0 if the stopwatch is not running.
     */
    [[nodiscard]] float getElapsedTime() const;

    /**
     * @brief Updates the stopwatch and returns the delta time in seconds.
     *
     * Calculates the time elapsed since the last tick and returns it as the delta time.
     * If the stopwatch is not running, it returns 0.
     *
     * @return The delta time in seconds. Returns 0 if the stopwatch is not running.
     */
    float tick();

    /**
     * @brief Gets the delta time in seconds.
     *
     * Returns the time difference between the current tick and the previous tick.
     *
     * @return The delta time in seconds.
     */
    [[nodiscard]] float getDeltaTime() const;

    /**
     * @brief Deleted copy constructor to prevent copying of the Stopwatch object.
     *
     * The Stopwatch class follows the singleton pattern and does not allow copying.
     */
    Stopwatch(const Stopwatch&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent assignment of the Stopwatch object.
     *
     * The Stopwatch class follows the singleton pattern and does not allow assignment.
     */
    Stopwatch& operator=(const Stopwatch&) = delete;

private:
    /**
     * @brief Private constructor to initialize the Stopwatch instance.
     *
     * Initializes the stopwatch to a stopped state with delta time set to 0.
     */
    Stopwatch();

    // Private member variables
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime; ///< The start time of the stopwatch.
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime; ///< The time of the previous tick.
    float deltaTime; ///< The delta time between ticks.
    bool running; ///< Flag to track whether the stopwatch is running.
};

#endif // STOPWATCH_H
