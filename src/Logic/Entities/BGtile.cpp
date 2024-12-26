//
// Created by karan on 14/11/2024.
//

#include "BGtile.h"

void BGtile::update(float deltaTime) {
    notify();
}

BGtile::BGtile(float x, float y) : Entity(x, y) {
    width = 30;
    height = 30;
    EntityType_var = EntityType::BG_TILE;
    collidable = false;

}