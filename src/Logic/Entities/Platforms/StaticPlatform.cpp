//
// Created by Skip on 15/11/2024.
//

#include "StaticPlatform.h"

StaticPlatform::StaticPlatform(float x, float y) : Platform(x, y) {
    type = PlatformType::STATIC;
}

StaticPlatform::~StaticPlatform() = default;

void StaticPlatform::update(float deltaTime) {
    // Static platforms do not move
}

