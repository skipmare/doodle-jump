//
// Created by Skip on 15/11/2024.
//

#include "DisappearingPlatform.h"

// DisappearingPlatform constructor
DisappearingPlatform::DisappearingPlatform(float x, float y) : StaticPlatform(x, y) {

    type = PlatformType::DISAPPEARING;
    disappeared = false;
    jumptrigger = false;

}

// DisappearingPlatform destructor
DisappearingPlatform::~DisappearingPlatform() = default;

// Updates the platform
void DisappearingPlatform::update(float deltaTime) {
    if(hasCollided) {
        this->setOutOfView(true);
    }
    notify();
}

// This method is used to check if the platform has disappeared
bool DisappearingPlatform::isDisappeared() const {
    return disappeared;
}
