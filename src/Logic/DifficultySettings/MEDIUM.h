// MEDIUM.h
#pragma once
#include "DifficultySettings.h"

class MEDIUM : public DifficultySettings {
public:
    MEDIUM() {
        ChanceBonus = 0.05f;
        ChanceStatic = 0.45f;
        ChanceHorizontal = 0.2f;
        ChanceVertical = 0.1f;
        ChanceDisappearing = 0.15f;
        minDistance = 155.0f;
        maxDistance = 161.0f;
    }
};