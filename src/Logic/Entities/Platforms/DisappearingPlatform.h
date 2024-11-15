//
// Created by Skip on 15/11/2024.
//

#ifndef DISAPPEARINGPLATFORM_H
#define DISAPPEARINGPLATFORM_H

#include "StaticPlatform.h"

class DisappearingPlatform : public StaticPlatform {
public:
    // Constructor and destructor
    DisappearingPlatform(int x, int y);
    ~DisappearingPlatform() override;

    // Updates the platform
    void update(float deltaTime) override;

    // This method is used to check if the platform has disappeared
    bool isDisappeared() const;

private:
    float disappearTime;
    float elapsedTime;
    bool disappeared;
};

#endif // DISAPPEARINGPLATFORM_H