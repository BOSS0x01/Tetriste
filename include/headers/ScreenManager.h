#pragma once
#include "mainMenu.h"

class ScreenManager
{
private:
    enum Screens
    {
        Menu,
        Play
    };
    static ScreenManager *sInstance;
    MainMenu *mMainMenu;
    InputManager *mInputMgr;
    Screens mCurrentScreen = Menu;

public:
    static ScreenManager *Instance();
    static void Release();

    void Update();
    void Render();

private:
    ScreenManager();
    ~ScreenManager();
};