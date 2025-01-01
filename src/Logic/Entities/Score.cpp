// Score.cpp
#include "Score.h"
#include <iostream>
Score::Score(float x, float y) : Entity(x, y), _score(0),bestScore(0) {}

void Score::update(float deltaTime) {
    notify();
}

void Score::setScore(int score) {
    _score = score;
    if(_score > bestScore) {
        bestScore = _score;
    }
}

void Score::ResetScore() {
    _score = 0;
}