//
// Created by Skip on 16/11/2024.
//

#include "Jetpack.h"

Jetpack::Jetpack(float x, float y, std::shared_ptr<Platform> platform) : Bonus(x,  y,platform) {
    type = JETPACK;
    collisionOnLand = false;
}