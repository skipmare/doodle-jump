#include "Platform.h"

//constructor
Platform::Platform(int x, int y) : Entity(x, y) {
    width = 6;
    height = 2;
}

//destructor
Platform::~Platform() {}

//update method
void Platform::update(float deltaTime) {}

//player collision method
bool Platform::hasCollidedWithPlayer(Entity &player) const{
    //checks if the player has collided with the platform
    return false;

}
