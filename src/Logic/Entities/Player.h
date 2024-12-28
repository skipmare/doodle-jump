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

    // Method to move the player left or right
    void move(int direction);

    // Method to set whether the player has collided with an object (platform/bonus)
    void SetHasCollided(bool collisionBool);

    // Getters for player velocity
    [[nodiscard]] float getVelocityX() const { return velocityX; }

    // Getters for player state
    [[nodiscard]] bool isJumping() const { return isJumpingState; }
    [[nodiscard]] bool isFalling() const { return isFallingState; }
    [[nodiscard]] float getVelocityY() const { return velocityY; }
    [[nodiscard]] float getJumpForce() const {return jumpForce;}
    [[nodiscard]] float getGravity() const {return gravity;}
    [[nodiscard]] bool getCollisionWithPlatform() const {return CollisionWithPlatform;}

    // Setters for player state
    void setCWP(bool CWP);
    void setJumping(); // Set player to jumping state
    void setFalling(); // Set player to falling state
    void setisgoingleft(bool goingleft); // Set player to falling state
    // apply Bonus effect
    void applyBonusEffect(BonusType bonusType);

private:
    bool isJumpingState = false; // Player is jumping
    bool isFallingState = false;  // Player is falling
    float gravity = 8.0f;         // Gravity value
    float jumpForce = 750.0f;      // Force applied when jumping
    bool hasCollided = false;
    bool BonusEffect = false;
    bool isgoingleft = false;
    bool CollisionWithPlatform = false;
    float BonusEffectTime = 0.0f;
};

#endif // INC_2024_PROJECT_SKIPMARE_PLAYER_H