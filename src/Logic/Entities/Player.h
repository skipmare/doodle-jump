//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_PLAYER_H
#define INC_2024_PROJECT_SKIPMARE_PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
    // Constructor and Destructor
    Player(float x, float y);
    ~Player() override = default;

    // Updates the player
    void update(float deltaTime) override;

    // Jump the player up
    void jump();


private:
    bool isFallingState = false; // Player is falling
    bool isJumpingState = false; // Player is jumping
    bool BonusState = false; // Player is using a bonus
    bool isDead = false; // Player fell off the screen
    bool JetpackState = false; // Player is using the jetpack
    bool SpringState = false; // Player is using the spring
    int gravity = 2; // Gravity value
};


#endif //INC_2024_PROJECT_SKIPMARE_PLAYER_H
