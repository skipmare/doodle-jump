/// @file Score.h
/// @brief Declares the Score class, which manages the player's current and best scores.

#ifndef SCORE_H
#define SCORE_H

#include "Entity.h"

/// @brief Represents the player's score in the game.
class Score : public Entity {
public:
    /// @brief Constructs a Score object with the specified initial position.
    /// @param x The initial x-coordinate of the score display.
    /// @param y The initial y-coordinate of the score display.
    Score(float x, float y);

    /// @brief Updates the score's state.
    /// @param deltaTime Time elapsed since the last update, in seconds.
    void update(float deltaTime) override;

    /// @brief Sets the current score.
    /// @param score The new score to set.
    void setScore(int score);

    /// @brief Resets the current score to zero.
    void ResetScore();

    /// @brief Gets the current score.
    /// @return The current score.
    [[nodiscard]] int getScore() const { return _score; }

    /// @brief Gets the best score achieved.
    /// @return The best score.
    [[nodiscard]] int getBestScore() const { return bestScore; }

private:
    int _score; ///< The current score.
    int bestScore; ///< The best score achieved so far.
};

#endif // SCORE_H
