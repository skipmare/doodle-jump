// HARD.h
#pragma once
#include "DifficultySettings.h"

class HARD : public DifficultySettings {
public:
    HARD() {
        ChanceBonus = 0.05f;
        ChanceStatic = 0.3f;
        ChanceHorizontal = 0.25f;
        ChanceVertical = 0.2f;
        ChanceDisappearing = 0.3f;
        minDistance = 50.0f;
        maxDistance = 300.0f;
    }
};