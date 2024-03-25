#pragma once
#include "Texture.h"
#include "Timer.h"
#include "ScoreCounter.h"
#include "TimerCountDown.h"
#include "InputManager.h"
#include "Shape.h"
#include "NextPieceGenerator.h"
using namespace QuickSDL;

class PlaySideBar : public GameEntity
{
private:
    Shape *tmpShapes[5];
    Texture *mBackground;
    Texture *NextPieceHolders[5];
    InputManager *mInputMgr;

    ScoreCounter *mScore;
    Texture *mScoreLabel;

    Timer *mTimer;
    Texture *mTimerLogo;
    TimerCountDown *mTimerCountDown;

    Texture *mNextPieceLabel;

    NextPieceGenerator *mNextShape;

public:
    PlaySideBar();
    ~PlaySideBar();

    Shape *getNextShape();

    void Update();
    void Render();
};