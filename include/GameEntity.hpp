#pragma once
#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"

class GameEntity {
    // Attributes
    private:
        // Textured rectangle should be called "sprite" actually
        // we make it a pointer to prevent forced initialization
        TexturedRectangle* sprite;

    // Methods
    public:
        GameEntity();
        GameEntity(const char* filepath, const SDL_Rect &rect);

        void update();
        void render();

        // the whole point is that we can change certain values of the TexturedRectangle
        // this makes TR the defacto class for everything position and dimension related.
        TexturedRectangle &getTexturedRectangle() const;

        ~GameEntity();
};