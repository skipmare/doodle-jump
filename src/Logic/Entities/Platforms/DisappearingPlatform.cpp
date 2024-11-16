//
// Created by Skip on 15/11/2024.
//

#include "DisappearingPlatform.h"

// DisappearingPlatform constructor
DisappearingPlatform::DisappearingPlatform(float x, float y) : StaticPlatform(x, y) {
    disappearTime = 2.0f;
    elapsedTime = 0.0f;
    type = PlatformType::DISAPPEARING;
    disappeared = false;

}

// DisappearingPlatform destructor
DisappearingPlatform::~DisappearingPlatform() = default;

// Updates the platform
void DisappearingPlatform::update(float deltaTime) {
    //to do: implement update method
}

// This method is used to check if the platform has disappeared
bool DisappearingPlatform::isDisappeared() const {
    return disappeared;
}

