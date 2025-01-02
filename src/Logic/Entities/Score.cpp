/// @file Score.cpp
/// @brief Implements the Score class, which tracks the player's current and best scores.

#include "Score.h"
#include <iostream>

/// @brief Constructs a Score object with the specified initial position.
/// @param x The initial x-coordinate of the score display.
/// @param y The initial y-coordinate of the score display.
Score::Score(float x, float y) : Entity(x, y), _score(0), bestScore(0) {}

/// @brief Updates the score's state.
/// @param deltaTime Time elapsed since the last update, in seconds.
void Score::update(float deltaTime) {
    notify(); ///< Notify observers of score updates.
}

/// @brief Sets the current score.
/// @param score The new score to set.
void Score::setScore(int score) {
    _score = score;
    if (_score > bestScore) {
        bestScore = _score; ///< Updates the best score if the current score exceeds it.
    }
}

/// @brief Resets the current score to zero.
void Score::ResetScore() {
    _score = 0;
}
