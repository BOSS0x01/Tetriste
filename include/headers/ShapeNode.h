#pragma once

#include <iostream>
#include "Shape.h"
class ShapeNode
{
private:
    Shape *mShape;

    ShapeNode *nextInList;
    ShapeNode *prevInList;

    ShapeNode *nextInSubList;
    ShapeNode *prevInSubList;

    ShapeNode *nextColor;
    ShapeNode *prevColor;

    ShapeNode *nextShape;
    ShapeNode *prevShape;

public:
    ShapeNode();
    ShapeNode(Shape *mShape);
    ~ShapeNode();

    ShapeNode *getNextInList();
    void setNextInList(ShapeNode *nextInList);
    ShapeNode *getPrevInList();
    void setPrevInList(ShapeNode *prevInList);

    ShapeNode *getNextInSubList();
    void setNextInSubList(ShapeNode *nextInList);
    ShapeNode *getPrevInSubList();
    void setPrevInSubList(ShapeNode *nextInList);

    ShapeNode *getNextShape();
    void setNextShape(ShapeNode *next);
    ShapeNode *getPrevShape();
    void setPrevShape(ShapeNode *next);

    ShapeNode *getNextColor();
    void setNextColor(ShapeNode *next);
    ShapeNode *getPrevColor();
    void setPrevColor(ShapeNode *next);

    Shape *getShape();
    void setShape(Shape *mShape);
};

ShapeNode::ShapeNode() : mShape(nullptr), nextInList(nullptr), prevInList(nullptr), nextInSubList(nullptr), prevInSubList(nullptr), nextColor(nullptr), prevColor(nullptr), nextShape(nullptr), prevShape(nullptr) {}

ShapeNode::ShapeNode(Shape *mShape) : mShape(mShape), nextInList(nullptr), prevInList(nullptr), nextInSubList(nullptr), prevInSubList(nullptr), nextColor(nullptr), prevColor(nullptr), nextShape(nullptr), prevShape(nullptr) {}

void ShapeNode::setNextInList(ShapeNode *nextInList)
{
    this->nextInList = nextInList;
}

ShapeNode *ShapeNode::getNextInList()
{
    return nextInList;
}

void ShapeNode::setPrevInList(ShapeNode *prevInList)
{
    this->prevInList = prevInList;
}

ShapeNode *ShapeNode::getPrevInList()
{
    return prevInList;
}

void ShapeNode::setNextInSubList(ShapeNode *nextInSubList)
{
    this->nextInSubList = nextInSubList;
}

ShapeNode *ShapeNode::getNextInSubList()
{
    return nextInSubList;
}

void ShapeNode::setPrevInSubList(ShapeNode *prevInSubList)
{
    this->prevInSubList = prevInSubList;
}

ShapeNode *ShapeNode::getPrevInSubList()
{
    return prevInSubList;
}

void ShapeNode::setNextColor(ShapeNode *nextColor)
{
    this->nextColor = nextColor;
}

ShapeNode *ShapeNode::getNextColor()
{
    return nextColor;
}

void ShapeNode::setPrevColor(ShapeNode *prevColor)
{
    this->prevColor = prevColor;
}

ShapeNode *ShapeNode::getPrevColor()
{
    return prevColor;
}

void ShapeNode::setNextShape(ShapeNode *nextShape)
{
    this->nextShape = nextShape;
}

ShapeNode *ShapeNode::getNextShape()
{
    return nextShape;
}

void ShapeNode::setPrevShape(ShapeNode *prevShape)
{
    this->prevShape = prevShape;
}

ShapeNode *ShapeNode::getPrevShape()
{
    return prevShape;
}

void ShapeNode::setShape(Shape *mShape)
{
    this->mShape = mShape;
}

Shape *ShapeNode::getShape()
{
    return mShape;
}

ShapeNode::~ShapeNode()
{
    if (mShape != nullptr)
        delete mShape;
    if (nextInList != nullptr)
        delete nextInList;
    if (prevInList != nullptr)
        delete prevInList;
}
