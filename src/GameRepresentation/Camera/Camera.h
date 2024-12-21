// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_CAMERA_H
#define INC_2024_PROJECT_SKIPMARE_CAMERA_H
#include <utility>

class Camera {
public:
    // Constructor initializes the camera with specific dimensions
    explicit Camera(float viewWidth, float viewHeight);

    // Transform world coordinates to screen (window) coordinates
    std::pair<float, float> transform(float x, float y) const;
    // Transform screen (window) coordinates to world coordinates
    std::pair<float, float> undotransform(float x, float y) const;

    // Update the camera position based on the player's position
    void updateCameraY(float PlayerY);
    // check if the player has reached a new max height
    bool isNewMax(float PlayerY);

    // Getters
    float getCameraX() const { return cameraX; }
    float getCameraY() const { return cameraY; }
    float getViewWidth() const { return viewWidth; }
    float getViewHeight() const { return viewHeight; }
    float getPlayerMaxY() const { return PlayerMaxY; }
    float getPlayerMaxYprev() const { return PlayerMaxYprev; }

private:
    float cameraX;
    float cameraY; // Current camera y position
    float viewWidth; // Width of the camera view
    float viewHeight; // Height of the camera view

    float PlayerMaxY;
    float PlayerMaxYprev;
};

#endif //INC_2024_PROJECT_SKIPMARE_CAMERA_H