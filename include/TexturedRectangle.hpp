#pragma once
#include <SDL2/SDL.h>
#include "Vector2.hpp"
#include "ResourceManager.hpp"
#include "global.hpp"
#include "Transform2D.hpp"

class TexturedRectangle : public Transform2D {
// Attributes
public:
    // should be linked to the Game entity, used only if absolutePosition is 0
    
private:
    SDL_Texture *texture;

// Methods
public:
    TexturedRectangle(const char *filepath, const Vector2 &dimensions);

    /**
     * Renders the sprite at the coordinate specified
     * Either absolute or relative with offset
     */
    void render();

private:
};