#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    static Stopwatch& getInstance() {
        static Stopwatch instance;
        return instance;
    }

    void start();
    void stop();
    double getElapsedTime() const;
    void tick();
    double getDeltaTime() const;

private:
    Stopwatch() = default;
    ~Stopwatch() = default;
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    std::chrono::duration<double> deltaTime;
    bool running = false;
};

#endif // STOPWATCH_H