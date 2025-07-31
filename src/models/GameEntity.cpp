#include "GameEntity.hpp"

GameEntity::GameEntity() :
    sprite(NULL),
    position({x: 0, y: 0}),
    collider(NULL)
{}

GameEntity::GameEntity(const Vector2 &position) :
    sprite(NULL),
    position(position),
    collider(NULL)
{}

void GameEntity::render() {
    if(this->sprite != NULL) {
        sprite->render();
    }
}

void GameEntity::update() {
    if(collider != NULL) {
        // this might be subject to change
        collider->setDimensions(this->sprite->dimensions);
    }
}

void GameEntity::addTexturedRectangle(
        const char* filepath, 
        const Vector2 &dimensions, 
        const Vector2 &offset
    ) 
{
    sprite = new TexturedRectangle(filepath, dimensions);
    sprite->setRelativePosition(position, offset);
}

void GameEntity::addTexturedRectangle(
        const char* filepath, 
        const SDL_Rect &rect 
    ) 
{
    sprite = new TexturedRectangle(filepath, {x: rect.w, y: rect.h});
    sprite->setAbsolutePosition({x: rect.x, y: rect.y});
}

void GameEntity::setPosition(const Vector2 &position) {
    this->position = position;
}

TexturedRectangle GameEntity::getTexturedRectangle() const {
    return *sprite;
}

Collider2D GameEntity::getCollider2D() const {
    return *collider;
}

GameEntity::~GameEntity() {
    delete sprite;
    delete collider;
}
