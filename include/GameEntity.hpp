#pragma once
#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"
#include "Collider2D.hpp"

class GameEntity {
    // Attributes
    private:
        // Textured rectangle should be called "sprite" actually
        // we make it a pointer to prevent forced initialization
        Vector2 position;
        TexturedRectangle* sprite;
        Collider2D* collider;
    // Methods
    public:
        GameEntity();
        /**
         * Full constructor
         * @param filepath uses a "dir/file" format, not a "./dir/file" format
         * @param rect pass it on the arguments like this {0,0,0,0} where args are equivalent to: (x,y,w,h) 
         */
        GameEntity(const char* filepath, const SDL_Rect &rect);

        void update();
        void render();
        void setPosition(const Vector2 &position);

        // the whole point is that we can change certain values of the TexturedRectangle
        TexturedRectangle &getTexturedRectangle() const;
        Collider2D &getCollider2D() const;

        ~GameEntity();
};