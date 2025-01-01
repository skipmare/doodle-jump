// MEDIUM.h
#pragma once
#include "DifficultySettings.h"

class MEDIUM : public DifficultySettings {
public:
    MEDIUM() {
        MaxPlat = 9;
        ChanceBonus = 0.05f;
        ChanceStatic = 0.55f;
        ChanceHorizontal = 0.25f;
        ChanceVertical = 0.1f;
        ChanceDisappearing = 0.15f;
        minDistance = 120.0f;
        maxDistance = 165.0f;
    }
};