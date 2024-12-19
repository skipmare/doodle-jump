#include "Camera.h"

// Constructor initializes the camera with specific dimensions
Camera::Camera(float viewWidth, float viewHeight)
    : cameraY(0), viewWidth(viewWidth), viewHeight(viewHeight), PlayerMaxY(0), cameraX(viewWidth / 2) {}

// Set the camera position based on the player's position
void Camera::setPosition(float playerX, float playerY) {
    // Update cameraY only if the player moves above the current maximum Y position
    if (playerY < PlayerMaxY) {
        cameraY = playerY; // Move the camera to follow the player
        PlayerMaxY = playerY; // Update the maximum Y position
    }
}

// Project normalized coordinates to pixel values
void Camera::project(float worldY, float& pixelY) const {
    // Adjust Y position based on the camera's current position
    pixelY = (worldY - cameraY) + (viewHeight / 2);
}

// Get the current camera Y position
float Camera::getCameraY() const {
    return cameraY;
}

// Get the current camera X position
float Camera::getCamerax() const {
    return cameraX;
}

// Get the width of the camera view
float Camera::getViewWidth() const {
    return viewWidth;
}

// Get the height of the camera view
float Camera::getViewHeight() const {
    return viewHeight;
}

// Check if a point is within the camera's view
bool Camera::isInView(float worldX, float worldY) const {
    // Check if the world coordinates are within the camera's view boundaries
    return (worldX >= (cameraX - (viewWidth / 2)) && worldX <= (cameraX + (viewWidth / 2)) &&
            worldY >= (cameraY - (viewHeight / 2)) && worldY <= (cameraY + (viewHeight / 2)));
}
