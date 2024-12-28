//
// Created by Skip on 15/11/2024.
//

#ifndef DISAPPEARINGPLATFORM_H
#define DISAPPEARINGPLATFORM_H

#include "StaticPlatform.h"

class DisappearingPlatform : public StaticPlatform {
public:
    // Constructor and destructor
    DisappearingPlatform(float x, float y);
    ~DisappearingPlatform() override;

    // Updates the platform
    void update(float deltaTime) override;

    // This method is used to check if the platform has disappeared
    [[nodiscard]] bool isDisappeared() const;

    //play disappear sound
    void playDisappearSound();

private:
    bool disappeared;
};

#endif // DISAPPEARINGPLATFORM_H