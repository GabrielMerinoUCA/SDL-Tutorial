#pragma once
#include <SDL2/SDL.h>

class TexturedRectangle
{
    // Attributes
public:
    SDL_Rect rect;
    SDL_Texture *texture;
    /** Forget encapsulation. Now performance is our best friend */
    SDL_Renderer *renderer;
    // Methods
public:
    /**
     * Full constructor
     * @param filepath use a "dir/file" format, not a "./dir/file" format
     * @param renderer send the renderer you want to render this with
     * @param rect pass it on the arguments like this {0,0,0,0} where args are equivalent to: (x,y,w,h) 
     */
    TexturedRectangle(const char *filepath, SDL_Renderer *renderer, SDL_Rect rect);
    /**
     * Constructor without rect initialization 
     */
    TexturedRectangle(const char *filepath, SDL_Renderer *renderer);
    ~TexturedRectangle();
    void update();
    void render();
};