// Score.cpp
#include "Score.h"
#include <iostream>
Score::Score(float x, float y) : Entity(x, y), _score(0) {}

void Score::update(float deltaTime) {
    notify();
}