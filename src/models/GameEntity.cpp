#include "GameEntity.hpp"

GameEntity::GameEntity() :
    sprite(NULL),
    position({x: 0, y: 0}),
    collider(NULL)
{}

GameEntity::GameEntity(const char* filepath, const SDL_Rect &rect) : 
    sprite(new TexturedRectangle(filepath, {rect.w, rect.h})),
    position({rect.x, rect.y}),
    collider(new Collider2D())
{ }

// Honestly, this just looks redundant
// not anymore B)
void GameEntity::render() {
    if(this->sprite != NULL) {
        sprite->render(this->position);
    }
}

void GameEntity::update() {
    // update collider to be the same position of the sprite
    if(collider != NULL) {
        collider->setAbsolutePosition(this->position);
        // this might be subject to change
        collider->setDimensions(this->sprite->dimensions);
    }
}

void GameEntity::setPosition(const Vector2 &position) {
    this->position = position;
}

TexturedRectangle &GameEntity::getTexturedRectangle() const {
    return *sprite;
}

Collider2D &GameEntity::getCollider2D() const {
    return *collider;
}

GameEntity::~GameEntity() {
    delete sprite;
    delete collider;
}
