#pragma once

#include <SDL2/SDL.h>
#include "Vector2.hpp"
#include "global.hpp"
#include "Transform2D.hpp"

class Collider2D : public Transform2D {
// Attributes
public:
    
// Methods
public:
    Collider2D(const Vector2 &dimensions);
    Collider2D();
    ~Collider2D();
    bool isColliding(const Collider2D &obj);
    void drawHitbox();
};