#pragma once
#include "Texture.h"
#include "Timer.h"
#include "InputManager.h"
#include "PlaySideBar.h"
#include "Board.h"
using namespace QuickSDL;

class PlayScreen : public GameEntity
{
private:
    PlaySideBar *mSideBar;
    Timer *mTimer;
    InputManager *mInputMgr;
    Board *mBoard;
    Texture *mControls;
    bool isPaused = true;

public:
    PlayScreen();
    ~PlayScreen();

    void Update();
    void Render();
};