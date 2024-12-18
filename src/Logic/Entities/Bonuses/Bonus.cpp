//
// Created by karan on 14/11/2024.
//

#include "Bonus.h"
#include "random.h" // Include your own random number generator header
#include <iostream> // For error handling

void Bonus::update(float deltaTime) {
    if (hasCollided && BonusType::JETPACK == type) {
        setOutOfView(true);
    }
    // Calculate the difference in platform position
    float deltaX = on_platform->getX() - prevPlatformX;
    float deltaY = on_platform->getY() - prevPlatformY;

    // Update the bonus position based on the platform's movement
    this->x += deltaX;
    this->y += deltaY;
    setPosition(this->x, on_platform->getY() - on_platform->getHeight() / 2 - height / 2);

    // Update previous platform positions
    prevPlatformX = on_platform->getX();
    prevPlatformY = on_platform->getY();

    notify();
}

// Constructor
Bonus::Bonus(float x, float y, std::shared_ptr<Platform> platform) : Entity(x, y), on_platform(platform) {
    // Generate a random x-coordinate within the platform's width
    float randomX = Random::getInstance().getRandomFloat(on_platform->getX() - on_platform->getWidth() / 2, on_platform->getX() + on_platform->getWidth() / 2 - width);
    this->x = randomX;
    setPosition(this->x, on_platform->getY() - on_platform->getHeight() / 2 - height / 2);
    width = 16;
    height = 16;
    EntityType_var = EntityType::BONUS;
    prevPlatformX = on_platform->getX();
    prevPlatformY = on_platform->getY();
    notify();
}
// Returns the type of the bonus
BonusType Bonus::getType() const {
    return type;
}

