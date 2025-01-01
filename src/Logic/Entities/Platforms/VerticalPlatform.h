//
// Created by Skip on 15/11/2024.
//

#ifndef VERTICALPLATFORM_H
#define VERTICALPLATFORM_H
#include "Platform.h"
#include <iostream>
class VerticalPlatform : public Platform {
public:

    // Constructor and destructor
    VerticalPlatform(float x, float y);
    ~VerticalPlatform() override;

    //override setposition
    void setPosition(float x, float initialY) override;

    // Updates the platform
    void update(float deltaTime) override;
private:
    float maxtravel = 70.0f;
};

#endif // VERTICALPLATFORM_H