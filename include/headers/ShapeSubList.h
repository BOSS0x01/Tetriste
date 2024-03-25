#include "ShapeList.h"

class ShapeSubList : public ShapeList
{
    ShapeSubList();
    ~ShapeSubList();
    void offsetLeft(ShapeList *);
    void insertFront(ShapeNode *);
    void insertBack(ShapeNode *);
};