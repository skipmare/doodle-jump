#include "Random.h"

/**
 * @class Random
 * @brief Provides utility functions for generating random numbers.
 *
 * The Random class provides methods for generating random floating-point numbers
 * within a specified range. It uses a random number generator and distributions
 * from the C++ standard library.
 */
Random::Random() : gen(std::random_device{}()) {}

/**
 * @brief Retrieves the singleton instance of the Random class.
 *
 * This method returns a reference to the singleton instance of the Random class,
 * ensuring that only one instance of the class is created throughout the program's lifetime.
 *
 * @return A reference to the singleton Random instance.
 */
Random& Random::getInstance() {
    static Random instance; ///< Static instance of the Random class (singleton pattern).
    return instance;
}

/**
 * @brief Generates a random floating-point number within the specified range.
 *
 * This method generates a random float between the given `min` and `max` values.
 * It uses a uniform real distribution to ensure that each number in the range has an equal
 * chance of being chosen.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @return A random floating-point number between `min` and `max`.
 */
float Random::getRandomFloat(float min, float max) {
    std::uniform_real_distribution<float> uniform_real_distribution(min, max); ///< Uniform distribution for floats
    return uniform_real_distribution(gen); ///< Generate and return a random float
}
