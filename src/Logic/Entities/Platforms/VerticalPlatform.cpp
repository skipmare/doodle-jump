//
// Created by Skip on 15/11/2024.
//

#include "VerticalPlatform.h"

// Constructor
VerticalPlatform::VerticalPlatform(float x, float y) : Platform(x, y) {
    velocityY = 0.1f;
    type = PlatformType::VERTICAL;
}

// Destructor
VerticalPlatform::~VerticalPlatform() = default;

// Updates the platform
void VerticalPlatform::update(float deltaTime) {
    y += velocityY * deltaTime;
}



