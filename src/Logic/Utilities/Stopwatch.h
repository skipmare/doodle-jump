#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    // Get the instance of the stopwatch
    static Stopwatch& getInstance() {
        static Stopwatch instance;
        return instance;
    }

    // Start the stopwatch
    void start();

    // Stop the stopwatch
    void stop();

    // Get the elapsed time in seconds
    double getElapsedTime() const;

    // Update the stopwatch and return the delta time
    double tick();

    // Get the delta time in seconds
    double getDeltaTime() const;

private:
    // Private constructor
    Stopwatch();

    // Deleted copy constructor and assignment operator
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    // Private member variables
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    double deltaTime;
    bool running;
};

#endif // STOPWATCH_H