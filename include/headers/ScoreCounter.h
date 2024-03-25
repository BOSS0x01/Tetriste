#pragma once
#include "Texture.h"
#include <vector>
using namespace QuickSDL;

class ScoreCounter : public GameEntity
{
private:
    std::vector<Texture *> mScore;
    int mFontSize, mCurrentScore;

public:
    ScoreCounter(int fontSize = 32);
    ScoreCounter(int score, int fontSize);

    ~ScoreCounter();

    void setScore(int);
    void incrementScore(int);
    void Render();

private:
    void ClearScore();
};