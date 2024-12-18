#ifndef JETPACK_H
#define JETPACK_H

#include "Bonus.h"

class Jetpack : public Bonus {
public:
    Jetpack(float x, float y, std::shared_ptr<Platform> platform);// Constructor
    ~Jetpack() override = default; // Destructor

};

#endif // JETPACK_H