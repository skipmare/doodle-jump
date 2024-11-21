//
// Created by karan on 14/11/2024.
//

#include "Bonus.h"

void Bonus::update(float deltaTime) {
    // Update logic for Bonus
    // For example, check if the bonus has been collected by the player
    // or if the duration has expired
    // This method will be called by the game loop to update the state of the bonus
    // based on the elapsed time (deltaTime)
    // You can add more logic here based on the specific behavior of the bonus
}

// Constructor
Bonus::Bonus(float x, float y) : Entity(x, y) {
    setPosition(x, y);
    width = 16;
    height = 16;
    EntityType_var = EntityType::BONUS;
    notify();
}

// Returns the type of the bonus
BonusType Bonus::getType() const {
    return type;
}


