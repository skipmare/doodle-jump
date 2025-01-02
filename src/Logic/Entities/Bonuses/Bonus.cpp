//
// Created by karan on 14/11/2024.
//

#include "Bonus.h"

/// @brief Updates the bonus position based on platform movement.
void Bonus::update(float deltaTime) {
    // Check if the bonus is of type Jetpack and has collided
    if (hasCollided && BonusType::JETPACK == type) {
        setOutOfView(true); ///< Mark the bonus as out of view when collected.
    }

    // Calculate the difference in platform position
    float deltaX = on_platform->getX() - prevPlatformX;
    float deltaY = on_platform->getY() - prevPlatformY;

    // Update the bonus position based on the platform's movement
    setPosition(this->x + deltaX, this->y + deltaY);

    // Update previous platform positions
    prevPlatformX = on_platform->getX();
    prevPlatformY = on_platform->getY();

    // Check if platform is out of view; mark bonus as out of view if true
    if (on_platform->getOutOfView()) {
        this->setOutOfView(true);
    }
}

/// @brief Constructs a Bonus object.
Bonus::Bonus(float x, float y, const std::shared_ptr<Platform>& platform) : Entity(x, y), on_platform(platform) {
    // Generate a random x-coordinate within the platform's width
    float randomX = Random::getInstance().getRandomFloat(on_platform->getX() - on_platform->getWidth() / 2,
                                                          on_platform->getX() + on_platform->getWidth() / 2 - width);
    this->x = randomX;
    setPosition(this->x, on_platform->getY() - on_platform->getHeight() / 2 - height / 2);
    width = 20;
    height = 20;
    EntityType_var = EntityType::BONUS;
    prevPlatformX = on_platform->getX();
    prevPlatformY = on_platform->getY();
    notify();
}

/// @brief Returns the type of the bonus.
BonusType Bonus::getType() const {
    return type;
}
