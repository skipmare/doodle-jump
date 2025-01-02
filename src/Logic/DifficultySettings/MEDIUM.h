#pragma once
#include "DifficultySettings.h"

/// @file MEDIUM.h
/// @brief Defines the settings for the MEDIUM difficulty level.

/// @class MEDIUM
/// @brief A derived class representing the MEDIUM difficulty settings.
/// 
/// This class sets the parameters for the MEDIUM difficulty level, with a balanced distribution of platform types,
/// and a moderate chance for bonus items to appear. The platform distance is also in a middle range.
class MEDIUM : public DifficultySettings {
public:
    /// @brief Constructs the MEDIUM difficulty settings with predefined values.
    MEDIUM() {
        MaxPlat = 9; ///< Set the maximum number of platforms.
        ChanceBonus = 0.05f; ///< Set the chance for a bonus.
        ChanceStatic = 0.55f; ///< Set the chance for a static platform.
        ChanceHorizontal = 0.25f; ///< Set the chance for a horizontal platform.
        ChanceVertical = 0.1f; ///< Set the chance for a vertical platform.
        ChanceDisappearing = 0.15f; ///< Set the chance for a disappearing platform.
        minDistance = 130.0f; ///< Set the minimum distance between platforms.
        maxDistance = 165.0f; ///< Set the maximum distance between platforms.
    }
};
