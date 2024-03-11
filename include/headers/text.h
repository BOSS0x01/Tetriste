#pragma once

#ifndef TEXT_H
#define TEXT_H
#include <sdl2/SDL.h>
#include <sdl2/SDL_ttf.h>
#include <iostream>
class Text
{
public:
    Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string message, SDL_Color color);
    static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string message, SDL_Color color);
    void display(int x, int y, SDL_Renderer *renderer) const;
    int getWidth() const;
    int getHeight() const;
    ~Text();

private:
    int _fontWidth;
    int _fontHeight;
    SDL_Texture *_txtTexture = nullptr;
    mutable SDL_Rect _txtRect;
};
#endif