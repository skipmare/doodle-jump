#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
    Random();
    ~Random() = default;

    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    static Random& getInstance();

    float getRandomFloat(float min, float max);

private:
    std::mt19937 gen;

};

#endif // RANDOM_H