#pragma once
#include "Texture.h"
#include "DoublyLinkedList.h"
#include "SubDoublyLinkedList.h"
#include "Shape.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace QuickSDL;
enum Lists
{
    Main_List,
    Color_RED_List,
    Color_YELLOW_List,
    Color_GREEN_List,
    Color_PURPLE_List,
    Shape_SQUARE_List,
    Shape_TRIANGLE_List,
    Shape_CERCLE_List,
    Shape_RHOMBUS_List
};
class Board : public GameEntity
{

private:
    int NUMBER_OF_SUB_LISTS = 9;
    SubDoublyLinkedList<Shape> *mSubLists[8];
    DoublyLinkedList<Shape> *mMainList;
    InputManager *mInputMgr;
    Texture *mBackground;
    int mShapePosX[15], mStartPositionIndex = 7, mEndPositionIndex = 7, mShapesCreated = 0;
    AudioManager *mAudioMgr;

public:
public:
    Board();
    ~Board();

    void AddShape(Shape *, bool);

    void Update();
    void Render();
    void balancePositions();

private:
    void insertShapeInSubLists(Shape *, bool isRight);
    int setPositionX();
};