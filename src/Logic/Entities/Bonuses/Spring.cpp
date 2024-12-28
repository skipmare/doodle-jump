//
// Created by Skip on 16/11/2024.
//

#include "Spring.h"

Spring::Spring(float x, float y, const std::shared_ptr<Platform> &platform) : Bonus( x,  y, platform) {
    type = SPRING;
    collisionOnLand = true;
}