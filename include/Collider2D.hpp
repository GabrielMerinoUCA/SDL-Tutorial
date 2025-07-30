#pragma once

#include <SDL2/SDL.h>
#include "Vector2.hpp"
#include "global.hpp"

class Collider2D {
    private:
    
    public:
    SDL_Rect colliderHitbox;
    Collider2D(const SDL_Rect &colliderHitbox);
    Collider2D();
    ~Collider2D();

    bool isColliding(const Collider2D &obj);
    // abosulte position means its cooordinates are relative to the window rather than a specific
    // object (offset/relative position)
    void setAbsolutePosition(const Vector2 &position); 
    void setDimensions(const Vector2 &dimensions);
    void drawHitbox();
};