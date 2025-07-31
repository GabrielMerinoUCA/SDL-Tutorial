#pragma once
#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"
#include "Collider2D.hpp"

// this class is kinda bugged, idk why but indentation is 8 spaces instead of 4 and no
// Im not manually changing it nor fixing it (at least for now...)

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
        GameEntity(const Vector2 &Vector2);

        void update();
        void render();
        /**
         * Add a new TexturedRectangle with positions relative to the ones of the current GameEntity
         * @param filepath uses a "dir/file" format, not a "./dir/file" format
         */
        void addTexturedRectangle(const char* filepath, const Vector2 &dimension, const Vector2 &positionOffset);
        /**
         * Add a new TexturedRectangle with absolute positions. Using Absolute position means
         * that you are responsible for updating the position of the TexturedRectangle rather 
         * than this class doing it automatically for you. Therefore this is better for static textures.
         * @param filepath uses a "dir/file" format, not a "./dir/file" format
         * @param rect you can pass it on the arguments like this {0,0,0,0} where args are equivalent to: (x,y,w,h)
         */
        void addTexturedRectangle(const char* filepath, const SDL_Rect &rect);
        void setPosition(const Vector2 &position);

        // the whole point is that we can change certain values of the TexturedRectangle
        TexturedRectangle getTexturedRectangle() const;
        Collider2D getCollider2D() const;

        ~GameEntity();
};