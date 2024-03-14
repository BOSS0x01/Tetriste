#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <sdl2/SDL.h>
class Timer
{
private:
    static Timer *sInstance;
    unsigned int mElapsedTicks;
    unsigned int mStartTicks;
    float mDeltaTime;
    float mTimeScale;

public:
    static Timer *Instance();
    static void Release();

    float deltaTime();

    float timeScale();
    void timeScale(float);

    void reset();
    void update();

private:
    Timer();
    ~Timer();
};
#endif