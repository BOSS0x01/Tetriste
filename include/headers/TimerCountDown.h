#pragma once
#include <vector>
#include "Texture.h"
#include "Timer.h"
using namespace QuickSDL;
class TimerCountDown : public GameEntity
{
private:
    std::vector<Texture *> mTimerCountDown;
    Timer *mTimer;
    int mSeconds, mMinutes;
    float mCurrentTime = 0, mDecrementUnit = 1.0f;
    bool mIsPaused = true;

public:
    TimerCountDown();
    TimerCountDown(int time);
    ~TimerCountDown();
    void setTimerCountDown(int time);
    void IncrementTimer(int addedTime);
    void Update();
    void Render();
    void ResumeTimer();
    void StopTimer();

private:
    void clearTimer();
};