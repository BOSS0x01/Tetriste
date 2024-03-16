#pragma once
#include "Texture.h"
#include "Timer.h"
#include "ScoreCounter.h"

using namespace QuickSDL;

class PlaySideBar : public GameEntity
{
private:
    Texture *mBackground;
    Timer *mTimer;
    ScoreCounter *mScore;

public:
    PlaySideBar();
    ~PlaySideBar();

    void Update();
    void Render();
};