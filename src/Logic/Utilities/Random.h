#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
    Random() : rng(std::random_device()()), distX(0, 500), distY(0, 800), distType(0, 1) {}

    float getRandomX() {
        return distX(rng);
    }

    float getRandomY() {
        return distY(rng);
    }

    int getRandomType() {
        return distType(rng);
    }

private:
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX;
    std::uniform_real_distribution<float> distY;
    std::uniform_int_distribution<int> distType;
};

#endif // RANDOM_H