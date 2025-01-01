// EASY.h
#pragma once
#include "DifficultySettings.h"

class EASY : public DifficultySettings {
public:
    EASY() {
        MaxPlat = 10;
        ChanceBonus = 0.08f;
        ChanceStatic = 0.7f;
        ChanceHorizontal = 0.1f;
        ChanceVertical = 0.05f;
        ChanceDisappearing = 0.15f;
        minDistance = 100.0f;
        maxDistance = 165.0f;
    }
};