#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include "Graphics.h"
#include "Timer.h"
class GameManager
{
private:
    static GameManager *sInstance;
    QuickSDL::Graphics *mGraphics;

    const int FPS = 60;
    float FRAME_TARGET_TIME = 1000.0f / FPS; // in seconds e.g 1/60 = 0.0166
    int timeToWait;

    SDL_Event mEvent;
    Timer *mTimer;

    bool mQuit;

public:
    static GameManager *Instance();
    static void Release();
    void run();

private:
    GameManager();
    ~GameManager();
};

#endif