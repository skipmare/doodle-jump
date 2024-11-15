#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Platform.h"

class StaticPlatform : public Platform {
public:

    // constructor and destructor
    StaticPlatform(int x, int y);
    ~StaticPlatform() override;

    // This method is used to update the platform
    void update(float deltaTime) override;

};

#endif // STATICPLATFORM_H