#include "Camera.h"

// Constructor initializes the camera with specific dimensions
Camera::Camera(float viewWidth, float viewHeight)
    : cameraY(viewHeight / 2), viewWidth(viewWidth), viewHeight(viewHeight), PlayerMaxY(viewHeight / 2),cameraX(viewWidth/2) {}

// Set the camera position based on the player's position
void Camera::setPosition(float playerX, float playerY) {
    // Update cameraY only if the player is above the current maximum Y position
    if (playerY > PlayerMaxY) {
        cameraY = playerY; // Move the camera up to the player's Y position
        PlayerMaxY = playerY; // Update the maximum Y position
    }
}

// Project normalized coordinates to pixel values
void Camera::project(float worldY, float& pixelY) const {
    // Since cameraX is static, we can use a fixed value for pixelX
    pixelY = (worldY - cameraY) + (viewHeight / 2); // Adjusting Y position based on cameraY
}

// Get the current camera Y position
float Camera::getCameraY() const {
    return cameraY; // Return the current camera Y position
}

// Get the current camera X position
float Camera::getCamerax() const {
    return cameraX;
}

// Get the width of the camera view
float Camera::getViewWidth() const {
    return viewWidth; // Return the width of the camera view
}

// Get the height of the camera view
float Camera::getViewHeight() const {
    return viewHeight; // Return the height of the camera view
}

// Check if a point is within the camera's view
bool Camera::isInView(float worldX, float worldY) const {
    // Check if the world coordinates are within the camera's view boundaries
    const float cameraX = viewWidth / 2; // Static X position centered
    return (worldX >= (cameraX - (viewWidth / 2)) && worldX <= (cameraX + (viewWidth / 2)) &&
            worldY >= (cameraY - (viewHeight / 2)) && worldY <= (cameraY + (viewHeight / 2)));
}