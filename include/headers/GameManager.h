#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Graphics.h"

class GameManager
{
private:
    static GameManager *sInstance;
    QuickSDL::Graphics *mGraphics;
    bool mQuit;
    SDL_Event mEvent;

public:
    static GameManager *Instance();
    static void Release();
    void run();

private:
    GameManager();
    ~GameManager();
};

#endif