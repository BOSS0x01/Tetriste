#pragma once

#ifndef SHAPE_H
#define SHAPE_H

#include <time.h>
#include <cstdlib>
#include <iostream>
#include "sdl2/SDL_image.h"
#include "constants.h"
#include "window.h"
enum class color
{
    red,
    yellow,
    green,
    blue
};
enum shapeType
{
    rectangle,
    cercle,
    triangle,
    rhombus
};

class Shape
{
private:
    mutable SDL_Rect _shape;
    SDL_Texture *_shapeTexture;
    int _r, _g, _b, _a;
    int _x, _y, _w, _h, color, type;
    std::string _textureUrl;
    int randomGenerator();

public:
    Shape(int, int, int, int, const char *);
    Shape(int x, int, int, int, int, int, int, int);
    ~Shape();
    void draw() const;
    void handleEvents(SDL_Event &);
    std::string toString();
    friend bool operator==(const Shape &, const Shape &);
};

#endif