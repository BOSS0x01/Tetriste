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
    ~Text();
    void display(int x, int y, SDL_Renderer *renderer) const;
    static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string message, SDL_Color color);

private:
    SDL_Texture *_txtTexture = nullptr;
    mutable SDL_Rect _txtRect;
};
#endif