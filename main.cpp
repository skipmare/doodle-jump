#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Doodle Jump - Jump and Move Test");

    // Create a player instance
    Player player(400, 300); // Start in the middle of the window

    // Create a rectangle shape to represent the player
    sf::RectangleShape playerShape(sf::Vector2f(40, 50)); // Width and height of the player
    playerShape.setFillColor(sf::Color::Green); // Set the color of the player box

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle input directly in main
        int direction = 0; // Initialize direction

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            // Move left
            direction = -1; // Set direction to left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            // Move right
            direction = 1; // Set direction to right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump(); // Call jump method when space is pressed
        }

        // Move the player based on input
        player.move(direction);

        // Update the player state
        player.update(0.016f); // Assuming ~60 FPS, so deltaTime is approximately 1/60

        // Update the position of the player shape based on the player's position
        playerShape.setPosition(player.getX(), player.getY());

        // Clear the window
        window.clear();

        // Draw the player shape
        window.draw(playerShape);

        // Display the contents of the window
        window.display();
    }

    return 0;
}