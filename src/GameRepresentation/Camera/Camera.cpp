#include "Camera.h"
#include <iostream>
#include <algorithm>

// Constructor initializes the camera with specific dimensions
Camera::Camera(float viewWidth, float viewHeight)
    : cameraY(viewHeight/2), viewWidth(viewWidth), viewHeight(viewHeight), PlayerMaxY(viewHeight/2), cameraX(viewWidth / 2),normalizedCameraY(cameraY) {}

#include <cmath>  // For std::abs()

void Camera::setPosition(float playerY, float deltaTime, float playerVelocityY) {
    // Compute the desired camera Y position to keep the player near the center of the screen
    float CurrentBottom = cameraY + viewHeight / 2;
    float PlayerYtoCameraY = CurrentBottom - (viewHeight - playerY);  // Player's relative position to camera's bottom

    // Calculate the absolute difference between PlayerYtoCameraY and cameraY
    float difference = std::abs(PlayerYtoCameraY - cameraY);

    // Move the camera if the absolute difference exceeds a certain threshold
    if (difference > 0.5f) {  // Adjust this threshold value as needed
        // Move the camera towards the player's relative position
        if (PlayerYtoCameraY < cameraY) {
            cameraY += playerVelocityY * deltaTime;
        }if(playerY<0) {
            cameraY = PlayerYtoCameraY;
        }

        // Debug output to track the values
        std::cout << "Camera Position: " << cameraY << std::endl;
        std::cout << "PlayerYtoCameraY: " << PlayerYtoCameraY << std::endl;
        std::cout << "Difference: " << difference << std::endl;
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
