// EASY.h
#pragma once
#include "DifficultySettings.h"

class EASY : public DifficultySettings {
public:
    EASY() {
        ChanceBonus = 0.15f;
        ChanceStatic = 0.7f;
        ChanceHorizontal = 0.1f;
        ChanceVertical = 0.05f;
        ChanceDisappearing = 0.15f;
        minDistance = 140.0f;
        maxDistance = 161.0f;
    }
};