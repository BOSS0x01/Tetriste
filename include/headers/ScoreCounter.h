#pragma once
#include "Texture.h"
#include <vector>
using namespace QuickSDL;

class ScoreCounter : public GameEntity
{
private:
    std::vector<Texture *> mScore;

public:
    ScoreCounter();
    ~ScoreCounter();

    void setScore(int);
    void incrementScore(int);
    void Render();

private:
    void ClearScore();
};