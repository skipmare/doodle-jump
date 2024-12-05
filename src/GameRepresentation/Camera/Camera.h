// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_CAMERA_H
#define INC_2024_PROJECT_SKIPMARE_CAMERA_H

class Camera {
public:
    // Constructor initializes the camera with specific dimensions
    explicit Camera(float viewWidth, float viewHeight);

    // Set the camera position based on the player's position
    void setPosition(float playerX, float playerY);

    // Project normalized coordinates to pixel values
    void project(float worldY, float& pixelY) const;

    // Get the current camera position
    [[nodiscard]] float getCameraY() const;
    [[nodiscard]] float getCamerax() const;
    [[nodiscard]] float getViewWidth() const;
    [[nodiscard]] float getViewHeight() const;

    // Check if a point is within the camera's view
    [[nodiscard]] bool isInView(float worldX, float worldY) const;

private:
    float cameraX;
    float cameraY; // Current camera y position
    float viewWidth; // Width of the camera view
    float viewHeight; // Height of the camera view

    float PlayerMaxY;
};

#endif //INC_2024_PROJECT_SKIPMARE_CAMERA_H