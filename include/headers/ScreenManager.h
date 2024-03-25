#pragma once
#include "mainMenu.h"
#include "PlayScreen.h"
#include "AudioManager.h"

class ScreenManager
{
private:
    enum Screens
    {
        Menu,
        Play
    };
    static ScreenManager *sInstance;
    InputManager *mInputMgr;
    MainMenu *mMainMenu;
    PlayScreen *mPlayScreen;
    Screens mCurrentScreen = Menu;
    AudioManager *mAudioMgr;

public:
    static ScreenManager *Instance();
    static void Release();

    void Update();
    void Render();

private:
    ScreenManager();
    ~ScreenManager();
};