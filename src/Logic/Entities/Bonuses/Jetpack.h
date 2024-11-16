#ifndef JETPACK_H
#define JETPACK_H

#include "Bonus.h"

class Jetpack : public Bonus {
public:
    Jetpack(float x, float y);// Constructor
    ~Jetpack() override = default; // Destructor

};

#endif // JETPACK_H