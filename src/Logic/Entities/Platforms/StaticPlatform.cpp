//
// Created by Skip on 15/11/2024.
//

#include "StaticPlatform.h"

StaticPlatform::StaticPlatform(int x, int y) : Platform(x, y) {
    type = PlatformType::STATIC;
}

StaticPlatform::~StaticPlatform() = default;

void StaticPlatform::update(float deltaTime) {
    // Do nothing unless camera is moving
}

