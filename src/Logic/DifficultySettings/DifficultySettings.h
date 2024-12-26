// DifficultySettings.h
#pragma once
class DifficultySettings {
public:
    virtual ~DifficultySettings() = default;

    float ChanceBonus;
    float ChanceStatic;
    float ChanceHorizontal;
    float ChanceVertical;
    float ChanceDisappearing;
    float minDistance;
    float maxDistance;
};