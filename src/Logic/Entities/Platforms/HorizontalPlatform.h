//
// Created by Skip on 15/11/2024.
//

#ifndef HORIZONTALPLATFORM_H
#define HORIZONTALPLATFORM_H

#include "Platform.h"

class HorizontalPlatform : public Platform {
public:
    HorizontalPlatform(float x, float y);
    ~HorizontalPlatform() override;

    void update(float deltaTime) override;

};

#endif // HORIZONTALPLATFORM_H