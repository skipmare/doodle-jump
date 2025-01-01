// Score.h
#ifndef SCORE_H
#define SCORE_H

#include "Entity.h"

class Score : public Entity {
public:
    Score(float x, float y);
    void update(float deltaTime) override;
    void setScore(int score);
    void ResetScore();
    [[nodiscard]] int getScore() const { return _score; }
    [[nodiscard]] int getBestScore() const { return bestScore; }
private:
    int _score;
    int bestScore;
};

#endif // SCORE_H