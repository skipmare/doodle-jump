#pragma once

/// @file DifficultySettings.h
/// @brief Declares the base class DifficultySettings and its derived classes for different difficulty levels.

/// @class DifficultySettings
/// @brief A base class representing the settings for game difficulty.
///
/// This class defines the general parameters for different difficulty levels. It contains settings such as the
/// maximum number of platforms, chances for various types of platforms, and the minimum and maximum distances between
/// platforms.
class DifficultySettings {
public:
    /// @brief Default destructor for the DifficultySettings class.
    virtual ~DifficultySettings() = default;

    int MaxPlat; ///< The maximum number of platforms that can appear on the screen.
    float ChanceBonus; ///< The chance for a bonus to appear on a platform (as a float between 0 and 1).
    float ChanceStatic; ///< The chance for a static platform to appear.
    float ChanceHorizontal; ///< The chance for a horizontal platform to appear.
    float ChanceVertical; ///< The chance for a vertical platform to appear.
    float ChanceDisappearing; ///< The chance for a disappearing platform to appear.
    float minDistance; ///< The minimum distance between two consecutive platforms.
    float maxDistance; ///< The maximum distance between two consecutive platforms.
};
