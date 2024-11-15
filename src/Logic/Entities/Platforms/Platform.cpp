#include "Platform.h"

//constructor
Platform::Platform(float x, float y) : Entity(x, y) {}

//destructor
Platform::~Platform() {}

//update method
void Platform::update(float deltaTime) {}

//player collision method
bool Platform::hasCollidedWithPlayer(Entity &player) const{
    //checks if the player has collided with the platform
    return false;

}
