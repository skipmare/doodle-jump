// DifficultySettings.h
#pragma once
class DifficultySettings {
public:
    virtual ~DifficultySettings() = default;

    int MaxPlat;
    float ChanceBonus;
    float ChanceStatic;
    float ChanceHorizontal;
    float ChanceVertical;
    float ChanceDisappearing;
    float minDistance;
    float maxDistance;
};