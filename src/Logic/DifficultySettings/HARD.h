// HARD.h
#pragma once
#include "DifficultySettings.h"

class HARD : public DifficultySettings {
public:
    HARD() {
        MaxPlat = 6;
        ChanceBonus = 0.01f;
        ChanceStatic = 0.2f;
        ChanceHorizontal = 0.35f;
        ChanceVertical = 0.35f;
        ChanceDisappearing = 0.1f;
        minDistance = 160.0f;
        maxDistance = 170.0f;
    }
};