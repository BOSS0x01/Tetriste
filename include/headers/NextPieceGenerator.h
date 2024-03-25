#pragma once
#include "DoublyLinkedList.h"
#include "Shape.h"
#include "Texture.h"

using namespace QuickSDL;
class NextPieceGenerator : public GameEntity
{
private:
    DoublyLinkedList<Shape> *mList;
    const int SHAPE_TO_RENDER = 5;
    Shape *tmp;
    int mSize = 10;
    Texture *mTargetPositions[5];

public:
    NextPieceGenerator(Texture *[]);
    ~NextPieceGenerator();
    Shape *getNextShape();
    void Update();
    void Render();

private:
    Shape *getRandomShape();
};