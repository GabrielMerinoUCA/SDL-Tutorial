#include "Collider2D.hpp"

bool Collider2D::isColliding(const Collider2D &obj) {
    // Maybe createRect should be a singleton or something to prevent creating the same 
    // thing over and over again
    SDL_Rect rect1 = createRect();
    SDL_Rect rect2 = obj.createRect();
    return SDL_HasIntersection(&(rect1), &(rect2));
}

Collider2D::Collider2D(const Vector2 &dimensions) : Transform2D(dimensions) { }

Collider2D::Collider2D() : Transform2D({x: 0, y: 0}) { }

void Collider2D::drawHitbox() {
    SDL_SetRenderDrawColor(mainRenderer, 255, 0, 0, 255);
    SDL_Rect rect = createRect();
    SDL_RenderDrawRect(mainRenderer, &rect);
}

Collider2D::~Collider2D() {}