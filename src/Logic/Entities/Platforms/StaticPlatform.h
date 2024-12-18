#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Platform.h"

class StaticPlatform : public Platform {
public:

    // constructor and destructor
    StaticPlatform(float x, float y);
    ~StaticPlatform() override;

};

#endif // STATICPLATFORM_H