#include <SFML/Graphics.hpp>
#include "../Logic/Entities/Platforms/HorizontalPlatform.h"
#include "../Logic/Entities/Platforms/VerticalPlatform.h"
#include "PlatformView.h"
#include "Player.h"
#include "PlayerView.h"
#include "../Logic/Entities/Bonuses/Bonus.h"
#include "BonusView.h"

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platform and Bonus View Test");

    // Create instances of HorizontalPlatform and VerticalPlatform
    HorizontalPlatform horizontalPlatform(100, 300); // Example parameters
    VerticalPlatform verticalPlatform(400, 100); // Example parameters

    // Create PlatformView instances for each platform
    PlatformView horizontalPlatformView(horizontalPlatform);
    PlatformView verticalPlatformView(verticalPlatform);

    // Create a Player instance and PlayerView
    Player player(200, 500); // Starting position for the player
    PlayerView playerView(player); // Create the player view

    // Create a Bonus instance and BonusView
    Bonus bonus(300, 400); // Example parameters
    BonusView bonusView(bonus); // Create the bonus view

    // Attach views to the entities (assuming they are observers)
    horizontalPlatform.attach(&horizontalPlatformView);
    verticalPlatform.attach(&verticalPlatformView);
    player.attach(&playerView);
    bonus.attach(&bonusView);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle player input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-1); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(1); // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump(); // Jump
        }

        // Update platforms and bonus
        float deltaTime = 0.016f; // Assuming 60 FPS for simplicity
        horizontalPlatform.update(deltaTime);
        verticalPlatform.update(deltaTime);
        player.update(deltaTime); // Update the player
        bonus.update(deltaTime); // Update the bonus (if applicable)

        // Clear the window
        window.clear(sf::Color::Black);

        // Render platforms and bonus using their views
        horizontalPlatformView.render(window);
        verticalPlatformView.render(window);
        playerView.render(window); // Render the player view
        bonusView.render(window); // Render the bonus view

        // Display the contents of the window
        window.display();
    }

    return 0;
}