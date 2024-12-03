#include "Random.h"

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

float Random::getRandomFloat(float min, float max) {
    std::uniform_real_distribution<float> uniform_real_distribution(min, max);
    return uniform_real_distribution(gen);
}

