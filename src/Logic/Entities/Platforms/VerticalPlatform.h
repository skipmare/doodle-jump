//
// Created by Skip on 15/11/2024.
//

#ifndef VERTICALPLATFORM_H
#define VERTICALPLATFORM_H
#include "Platform.h"

class VerticalPlatform : public Platform {
public:

    // Constructor and destructor
    VerticalPlatform(float x, float y);
    ~VerticalPlatform() override;

    // Updates the platform
    void update(float deltaTime) override;
private:
    float initialY;
};

#endif // VERTICALPLATFORM_H