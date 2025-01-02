// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_CAMERA_H
#define INC_2024_PROJECT_SKIPMARE_CAMERA_H
#include <utility>

/**
 * @class Camera
 * @brief A class to manage the camera's position and transformation of coordinates.
 *
 * The Camera class handles the camera's position in the game world, updating based on the player's position,
 * and provides methods to transform coordinates between world space and screen space.
 */
class Camera {
public:
    /**
     * @brief Constructs a Camera object with specific dimensions.
     *
     * @param viewWidth The width of the camera view (in world units).
     * @param viewHeight The height of the camera view (in world units).
     */
    explicit Camera(float viewWidth, float viewHeight);

    /**
     * @brief Transforms world coordinates to screen (window) coordinates.
     *
     * Converts the provided world coordinates (x, y) to the corresponding screen coordinates
     * based on the camera's position and view size.
     *
     * @param x The x-coordinate in world space.
     * @param y The y-coordinate in world space.
     * @return A pair of float values representing the screen (window) coordinates.
     */
    std::pair<float, float> transform(float x, float y) const;

    /**
     * @brief Transforms screen (window) coordinates to world coordinates.
     *
     * Converts the provided screen coordinates (x, y) back to world coordinates.
     *
     * @param x The x-coordinate on the screen.
     * @param y The y-coordinate on the screen.
     * @return A pair of float values representing the world coordinates.
     */
    std::pair<float, float> undotransform(float x, float y) const;

    /**
     * @brief Updates the camera's y-position based on the player's y-position.
     *
     * Adjusts the camera's position so that it follows the player in the vertical direction.
     *
     * @param PlayerY The current y-position of the player in the world.
     */
    void updateCameraY(float PlayerY);

    /**
     * @brief Checks if the player has reached a new maximum height.
     *
     * Determines if the player has reached a higher vertical position than before,
     * indicating a new "max height" in the game.
     *
     * @param PlayerY The current y-position of the player.
     * @return True if the player has reached a new max height, false otherwise.
     */
    bool isNewMax(float PlayerY);

    // Getters

    /**
     * @brief Gets the current x-position of the camera.
     *
     * @return The current x-coordinate of the camera.
     */
    float getCameraX() const { return cameraX; }

    /**
     * @brief Gets the current y-position of the camera.
     *
     * @return The current y-coordinate of the camera.
     */
    float getCameraY() const { return cameraY; }

    /**
     * @brief Gets the width of the camera view.
     *
     * @return The width of the camera's view (in world units).
     */
    float getViewWidth() const { return viewWidth; }

    /**
     * @brief Gets the height of the camera view.
     *
     * @return The height of the camera's view (in world units).
     */
    float getViewHeight() const { return viewHeight; }

    /**
     * @brief Gets the player's maximum y-position.
     *
     * @return The highest y-coordinate the player has reached.
     */
    float getPlayerMaxY() const { return PlayerMaxY; }

    /**
     * @brief Gets the player's previous maximum y-position.
     *
     * @return The previous highest y-coordinate the player reached.
     */
    float getPlayerMaxYprev() const { return PlayerMaxYprev; }

    /**
     * @brief Resets the camera's position and properties to their initial state.
     */
    void resetCamera();

private:
    float cameraX; /**< The x-coordinate of the camera's position. */
    float cameraY; /**< The y-coordinate of the camera's position. */
    float viewWidth; /**< The width of the camera's view in world units. */
    float viewHeight; /**< The height of the camera's view in world units. */

    float PlayerMaxY; /**< The highest y-coordinate the player has reached. */
    float PlayerMaxYprev; /**< The previous highest y-coordinate the player reached. */
};

#endif //INC_2024_PROJECT_SKIPMARE_CAMERA_H
