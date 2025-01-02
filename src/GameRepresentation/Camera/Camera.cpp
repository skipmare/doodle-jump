#include "Camera.h"

// Constructor initializes the camera with specific dimensions
/**
 * @brief Constructs a Camera object with specific dimensions.
 *
 * The constructor sets the initial position of the camera at the center of the screen
 * and initializes other camera properties like view dimensions and the player's max height.
 *
 * @param viewWidth The width of the camera view (in world units).
 * @param viewHeight The height of the camera view (in world units).
 */
Camera::Camera(float viewWidth, float viewHeight)
    : cameraX(viewWidth / 2), // Camera starts at the center of the screen
      cameraY(viewHeight / 2), // Camera starts at the center of the screen
      viewWidth(viewWidth), // Camera view width(400)
      viewHeight(viewHeight), // Camera view height(800)
      PlayerMaxY(viewHeight / 2), // Player starts at the center of the screen
      PlayerMaxYprev(viewHeight / 2) // Player starts at the center of the screen
{}

// Transform world coordinates to screen (window) coordinates
/**
 * @brief Transforms world coordinates to screen (window) coordinates.
 *
 * Converts the given world coordinates (x, y) to screen coordinates, adjusting for the camera's
 * position and the view height.
 *
 * @param x The x-coordinate in world space.
 * @param y The y-coordinate in world space.
 * @return A pair of float values representing the screen coordinates (x, y).
 */
std::pair<float, float> Camera::transform(float x, float y) const {
    return {x, y - cameraY + viewHeight / 2};
}

// Transform screen (window) coordinates to world coordinates
/**
 * @brief Transforms screen (window) coordinates to world coordinates.
 *
 * Converts the given screen coordinates (x, y) back to world coordinates, adjusting for the camera's
 * position and the view height.
 *
 * @param x The x-coordinate on the screen.
 * @param y The y-coordinate on the screen.
 * @return A pair of float values representing the world coordinates (x, y).
 */
std::pair<float, float> Camera::undotransform(float x, float y) const {
    return {x, y + cameraY - viewHeight / 2};
}

// Check if the player has reached a new max height
/**
 * @brief Checks if the player has reached a new maximum height.
 *
 * Determines if the player has reached a higher vertical position than the current maximum height
 * and updates the player's max height values.
 *
 * @param PlayerY The current y-position of the player.
 * @return True if the player has reached a new max height, false otherwise.
 */
bool Camera::isNewMax(float PlayerY) {
    if(PlayerY > cameraY) {
        return false;
    }
    if (PlayerY < PlayerMaxY) {
        PlayerMaxYprev = PlayerMaxY;
        PlayerMaxY = PlayerY;
        return true;
    }
    return false;
}

// Update the camera position based on the player's position
/**
 * @brief Updates the camera's position based on the player's position.
 *
 * If the player has reached a new maximum height, the camera's vertical position (cameraY)
 * is updated to the player's new max height.
 *
 * @param PlayerY The current y-position of the player.
 */
void Camera::updateCameraY(float PlayerY) {
    if (isNewMax(PlayerY)) {
        cameraY = PlayerMaxY;
    }
}

// Reset the camera
/**
 * @brief Resets the camera's position and properties to their initial state.
 *
 * Resets the camera's y-position and the player's max height values to their default values
 * (the center of the screen).
 */
void Camera::resetCamera() {
    cameraY = viewHeight / 2;
    PlayerMaxY = viewHeight / 2;
    PlayerMaxYprev = viewHeight / 2;
}
