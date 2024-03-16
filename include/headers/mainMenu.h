#pragma once

#include "Texture.h"
#include "InputManager.h"
#include "ScoreCounter.h"
using namespace QuickSDL;

enum TitleIndexes
{
    StartIndex,
    ScoresIndex,
    QuitIndex
};
class MainMenu : public GameEntity
{
private:
    // Menu Elements
    GameEntity *menu;

    Texture *mTitles[3];
    // Original title positions
    Vector2 TiltePositions[3];

    // Handling inputs
    InputManager *mInputMgr;

    // Specifies the selected modes
    int mSelectedmode = -1;

    ScoreCounter *Score;

public:
    MainMenu();
    ~MainMenu();
    void Update();
    void Render();
    void changeSelecedMode(int);
    int getSelectedMode();

private:
    bool HandleInputs();
};
