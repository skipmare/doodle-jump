#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    // get the instance of the stopwatch
    static Stopwatch& getInstance() {
        static Stopwatch instance;
        return instance;
    }

    // start the stopwatch
    void start();

    // stop the stopwatch
    void stop();

    // get the elapsed time
    double getElapsedTime() const;

    // update the stopwatch
    void tick();

    // get the delta time
    double getDeltaTime() const;

private:
    // private constructor
    Stopwatch() = default;

    // default destructor
    ~Stopwatch() = default;

    // delete copy constructor and assignment operator
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    // start time
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    // previous time
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    // time duration
    std::chrono::duration<double> deltaTime;
    // running flag
    bool running = false;
};

#endif // STOPWATCH_H