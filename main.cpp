#include <SFML/Graphics.hpp>
#include "ConcreteFactory.h" // Include the factory header
#include "PlatformView.h"
#include "PlayerView.h"
#include "BonusView.h"

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(500, 800), "Entity Factory Test");

    // Create an instance of the concrete factory
    std::unique_ptr<ConcreteFactory> factory = std::make_unique<ConcreteFactory>(window);

    // Create a Player instance using the factory
    auto player = factory->createPlayer(200, 500);

    // Create instances of HorizontalPlatform and VerticalPlatform using the factory
    auto horizontalPlatform = factory->createPlatform(100, 300, PlatformType::HORIZONTAL);
    auto verticalPlatform = factory->createPlatform(400, 100, PlatformType::VERTICAL);
    auto staticPlatform = factory->createPlatform(600, 400, PlatformType::STATIC);

    // Create a Bonus instance and BonusView using the factory
    auto bonus = factory->createBonus(300, 400, BonusType::JETPACK);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle player input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->move(-1); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->move(1); // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player->jump(); // Jump
        }
        window.clear(sf::Color::Black);

        // Update entities
        float deltaTime = 0.016f; // Assuming 60 FPS for simplicity
        player->update(deltaTime); // Update the player
        horizontalPlatform->update(deltaTime); // Update the horizontal platform
        verticalPlatform->update(deltaTime); // Update the vertical platform
        bonus->update(deltaTime); // Update the bonus

        // Render the player and platforms

        // Display the contents of the window
        window.display();
    }

    return 0;
}