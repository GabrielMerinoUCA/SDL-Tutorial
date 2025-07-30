#include "Collider2D.hpp"

bool Collider2D::isColliding(const Collider2D &obj) {
    return SDL_HasIntersection(&(this->colliderHitbox), &(obj.colliderHitbox));
}

Collider2D::Collider2D(const SDL_Rect &colliderHitbox) : colliderHitbox(colliderHitbox) { }

Collider2D::Collider2D() : colliderHitbox({0,0,0,0}) { }

void Collider2D::setAbsolutePosition(const Vector2 &position) {
    this->colliderHitbox.x = position.x;
    this->colliderHitbox.y = position.y;
}

void Collider2D::setDimensions(const Vector2 &dimensions) {
    this->colliderHitbox.w = dimensions.x;
    this->colliderHitbox.h = dimensions.y;
}

void Collider2D::drawHitbox() {
    SDL_SetRenderDrawColor(mainRenderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(mainRenderer, &colliderHitbox);
}

Collider2D::~Collider2D() {}