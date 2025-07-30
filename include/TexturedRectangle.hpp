#pragma once
#include <SDL2/SDL.h>
#include "Vector2.hpp"

class TexturedRectangle {
    // Attributes
public:
    Vector2 dimensions;
    SDL_Texture *texture;
    // Methods
public:
    
    TexturedRectangle(const char *filepath, const Vector2 &dimensions);
    void setDimension(const Vector2 &dimensions);
    // A better way of doing this might be to make a pointer to 
    // the Game entity's position variable.
    void render(const Vector2 &texturePosition);
};