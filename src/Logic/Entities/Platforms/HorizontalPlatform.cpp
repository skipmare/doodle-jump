//
// Created by Skip on 15/11/2024.
//

#include "HorizontalPlatform.h"

// Constructor
HorizontalPlatform::HorizontalPlatform(float x, float y) : Platform(x, y) {
    type = PlatformType::HORIZONTAL;
    velocityX = 0.1f;
}

// Destructor
HorizontalPlatform::~HorizontalPlatform() = default;

// Updates the platform
void HorizontalPlatform::update(float deltaTime) {
    x += velocityX * deltaTime;
}



