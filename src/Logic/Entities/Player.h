// Player.h
#ifndef INC_2024_PROJECT_SKIPMARE_PLAYER_H
#define INC_2024_PROJECT_SKIPMARE_PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    // Constructor
    Player(float x, float y);

    // Updates the player's state
    void update(float deltaTime) override;

    // Method to make the player jump
    void jump();

    // Method to reset the player's state when landing
    void land();

    // Method to move the player left or right
    void move(int direction);

    // Method to set whether the player has collided with an object (platform/bonus)
    void SetHasCollided(bool collisionBool) {
        hasCollided = collisionBool;
    }

    // Getters for player velocity
    [[nodiscard]] float getVelocityX() const { return velocityX; }

    // Getters for player state
    [[nodiscard]] bool isJumping() const { return isJumpingState; }
    [[nodiscard]] bool isFalling() const { return isFallingState; }
    [[nodiscard]] float getVelocityY() const { return velocityY; }
    [[nodiscard]] bool getHasCollided() const {return hasCollided;}

    // Setters for player state
    void setJumping(); // Set player to jumping state
    void setFalling(); // Set player to falling state

    // apply Bonus effect
    void applyBonusEffect(BonusType bonusType);



private:
    bool isJumpingState = false; // Player is jumping
    bool isFallingState = false;  // Player is falling
    float gravity = 2.0f;         // Gravity value
    float jumpForce = 250.0f;      // Force applied when jumping
    bool hasCollided = false;
    bool BonusEffect = false;
};

#endif // INC_2024_PROJECT_SKIPMARE_PLAYER_H