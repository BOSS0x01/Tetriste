#pragma once
#include "Texture.h"
#include "Timer.h"
#include "InputManager.h"
#include "PlaySideBar.h"
using namespace QuickSDL;

class PlayScreen : public GameEntity
{
private:
    PlayScreen *mSideBar;
    Timer *mTimer;
    InputManager *mInputMgr;

public:
    PlayScreen();
    ~PlayScreen();

    void Update();
    void Render();
};