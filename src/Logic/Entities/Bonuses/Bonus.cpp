//
// Created by karan on 14/11/2024.
//

#include "Bonus.h"

void Bonus::update(float deltaTime) {
    if(hasCollided && BonusType::JETPACK == type) {
        setOutOfView(true);
    }
    notify();
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


