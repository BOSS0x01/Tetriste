
#ifndef SHAPE_H
#define SHAPE_H

#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Texture.h"

using namespace QuickSDL;
enum ShapeColor
{
    RED,
    YELLOW,
    GREEN,
    PURPLE
};
enum ShapeType
{
    SQUARE = 4,
    CERCLE = 5,
    TRIANGLE = 6,
    RHOMBUS = 7
};

class Shape : public GameEntity
{
private:
    int mWidth, mHeight;
    Texture *mShape;
    ShapeType mType;
    ShapeColor mColor;
 

public:
    std::string InitType(ShapeType) const;
    void InitColor(ShapeColor);
    ShapeColor getShapeColor();
    ShapeType getShapeType();


private:
public:
    Shape(ShapeType, ShapeColor);
    Shape(int, int, ShapeType, ShapeColor);
    ~Shape();
    void Render();
    void Update();

    friend bool operator==(const Shape &, const Shape &);
    friend std::ostream &operator<<(std::ostream &, const Shape &);
};

#endif