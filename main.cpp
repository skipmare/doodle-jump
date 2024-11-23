#include <SFML/Graphics.hpp>
#include "ConcreteFactory.h" // Include the factory header
#include "PlatformView.h"
#include "PlayerView.h"
#include "BonusView.h"
#include "BGtileView.h" // Include the BGtileView header
#include <iostream>

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

    // Create background tiles using the factory
    std::vector<std::unique_ptr<BGtile>> backgroundTiles;

    // Define the window dimensions
    const int windowWidth = 500;
    const int windowHeight = 800;
    const int tileSize = 16;

    // Calculate the number of tiles needed to cover the window and beyond
    int numTilesX = (windowWidth / tileSize) + 2; // Extra tiles for wrapping
    int numTilesY = (windowHeight / tileSize) + 2; // Extra tiles for wrapping

    // Create tiles across the width of the window
    for (int x = -tileSize; x < (numTilesX * tileSize); x += tileSize) {
        // Create tiles down the height of the window
        for (int y = -tileSize; y < (numTilesY * tileSize); y += tileSize) {
            // Create a tile at the calculated position
            auto tile = factory->createBGtile(x, y); // Assuming createBGTile exists
            backgroundTiles.push_back(std::move(tile));
        }
    }

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
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

        float deltaTime = 0.016f; // Assuming 60 FPS for simplicity
        // Update and render background tiles
        for (auto &tile : backgroundTiles) {
            tile->update(deltaTime);
        }

        player->update(deltaTime); // Update the player
        horizontalPlatform->update(deltaTime); // Update the horizontal platform
        verticalPlatform->update(deltaTime); // Update the vertical platform
        bonus->update(deltaTime); // Update the bonus

        // Display the contents of the window
        window.display();
    }

    return 0;
}