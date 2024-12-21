#include "Camera.h"
#include <iostream>

// Constructor initializes the camera with specific dimensions
Camera::Camera(float viewWidth, float viewHeight)
    : cameraX(viewWidth / 2), // Camera starts at the center of the screen
      cameraY(viewHeight / 2), // Camera starts at the center of the screen
      viewWidth(viewWidth), // Camera view width(400)
      viewHeight(viewHeight), // Camera view height(800)
      PlayerMaxY(viewHeight / 2), // Player starts at the center of the screen
      PlayerMaxYprev(viewHeight / 2) // Player starts at the center of the screen
        {}

// Transform world coordinates to screen (window) coordinates
std::pair<float, float> Camera::transform(float x, float y) const {
    return {x, y - cameraY + viewHeight / 2};
}

// Transform screen (window) coordinates to world coordinates
std::pair<float, float> Camera::undotransform(float x, float y) const {
    return {x, y + cameraY - viewHeight / 2};
}

// check if the player has reached a new max height
bool Camera::isNewMax(float PlayerY) {
    if(PlayerY>cameraY) {
        std::cout<<"PlayerY is greater than cameraY"<<std::endl;
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
void Camera::updateCameraY(float PlayerY) {
    if (isNewMax(PlayerY)) {
        cameraY = PlayerMaxY;
    }
}
