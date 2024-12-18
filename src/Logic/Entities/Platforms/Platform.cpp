#include "Platform.h"

//constructor
Platform::Platform(float x, float y) : Entity(x, y) {
    width = 100;
    height = 10;
    EntityType_var = EntityType::PLATFORM;
    collidable = true;
    collisionOnLand = true;
}

//destructor
Platform::~Platform() = default;

//update method
void Platform::update(float deltaTime) {
    notify();
}

//getPlatformType method

PlatformType Platform::getPlatformType() const {
    return type;
}
