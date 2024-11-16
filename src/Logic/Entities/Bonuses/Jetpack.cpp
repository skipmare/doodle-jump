//
// Created by Skip on 16/11/2024.
//

#include "Jetpack.h"

Jetpack::Jetpack(float x, float y) : Bonus(x,  y) {
    duration = 5;
    type = JETPACK;
}