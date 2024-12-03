#include "World.h"

// Constructor
World::World(ConcreteFactory& factory, float viewWidth, float viewHeight)
    : factory(factory), score(0), camera(viewWidth, viewHeight) { // Initialize camera with dimensions
    // Create the player entity
    player = factory.createPlayer(250, 250);
}
