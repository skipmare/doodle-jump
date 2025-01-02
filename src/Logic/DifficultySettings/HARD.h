#pragma once
#include "DifficultySettings.h"

/// @file HARD.h
/// @brief Defines the settings for the HARD difficulty level.

/// @class HARD
/// @brief A derived class representing the HARD difficulty settings.
/// 
/// This class sets the parameters for the HARD difficulty level, with fewer platforms and a lower chance for
/// bonuses. The platform types are more evenly distributed, and the platform distance is higher.
class HARD : public DifficultySettings {
public:
    /// @brief Constructs the HARD difficulty settings with predefined values.
    HARD() {
        MaxPlat = 6; ///< Set the maximum number of platforms.
        ChanceBonus = 0.01f; ///< Set the chance for a bonus.
        ChanceStatic = 0.2f; ///< Set the chance for a static platform.
        ChanceHorizontal = 0.35f; ///< Set the chance for a horizontal platform.
        ChanceVertical = 0.35f; ///< Set the chance for a vertical platform.
        ChanceDisappearing = 0.1f; ///< Set the chance for a disappearing platform.
        minDistance = 160.0f; ///< Set the minimum distance between platforms.
        maxDistance = 170.0f; ///< Set the maximum distance between platforms.
    }
};
