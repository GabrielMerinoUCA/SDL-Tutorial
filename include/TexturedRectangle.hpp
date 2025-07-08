#pragma once
#include <SDL2/SDL.h>

class TexturedRectangle
{
    // Attributes
public:
    SDL_Rect rect;
    SDL_Texture *texture;
    bool collision;
    // Methods
public:
    /**
     * Full constructor
     * @param filepath uses a "dir/file" format, not a "./dir/file" format
     * @param rect pass it on the arguments like this {0,0,0,0} where args are equivalent to: (x,y,w,h) 
     */
    TexturedRectangle(const char* filepath, const SDL_Rect &rect);
    // Detect collision
    bool isColliding(const TexturedRectangle &obj);
    void setPosition(const int &x, const int &y);
    void setDimension(const int &w, const int &h);
    void update();
    void render();
};