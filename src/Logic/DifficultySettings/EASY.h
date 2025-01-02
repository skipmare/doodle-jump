#pragma once
#include "DifficultySettings.h"

/// @file EASY.h
/// @brief Defines the settings for the EASY difficulty level.

/// @class EASY
/// @brief A derived class representing the EASY difficulty settings.
/// 
/// This class sets the parameters for the EASY difficulty level, with higher chances of platforms appearing and
/// more frequent bonus chances. The distance between platforms is also smaller compared to harder levels.
class EASY : public DifficultySettings {
public:
    /// @brief Constructs the EASY difficulty settings with predefined values.
    EASY() {
        MaxPlat = 10; ///< Set the maximum number of platforms.
        ChanceBonus = 0.08f; ///< Set the chance for a bonus.
        ChanceStatic = 0.7f; ///< Set the chance for a static platform.
        ChanceHorizontal = 0.1f; ///< Set the chance for a horizontal platform.
        ChanceVertical = 0.05f; ///< Set the chance for a vertical platform.
        ChanceDisappearing = 0.15f; ///< Set the chance for a disappearing platform.
        minDistance = 115.0f; ///< Set the minimum distance between platforms.
        maxDistance = 165.0f; ///< Set the maximum distance between platforms.
    }
};
