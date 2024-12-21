// Score.h
#ifndef SCORE_H
#define SCORE_H

#include "Entity.h"

class Score : public Entity {
public:
    Score(float x, float y);
    void update(float deltaTime) override;
    void setScore(int score) { _score = score; }
    int getScore() { return _score; }
    ~Score() = default;
private:
    int _score;
};

#endif // SCORE_H