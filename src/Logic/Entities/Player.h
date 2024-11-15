//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_PLAYER_H
#define INC_2024_PROJECT_SKIPMARE_PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
    // Constructor and Destructor
    Player(int x, int y);
    ~Player() override;

    // Updates the player
    void update(float deltaTime) override;


private:
    bool isFallingState = false;
    bool isJumpingState = false;

};


#endif //INC_2024_PROJECT_SKIPMARE_PLAYER_H
