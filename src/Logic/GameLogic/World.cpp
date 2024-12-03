#include "World.h"

// Constructor
World::World(std::shared_ptr<AbstractFactory> factory, float viewWidth, float viewHeight)
    : factory(factory), score(0), camera(viewWidth, viewHeight) { // Initialize camera with dimensions
    // Create the player entity
    player = factory->createPlayer(250, 250);
}
