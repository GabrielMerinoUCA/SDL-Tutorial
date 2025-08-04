#include "GameEntity.hpp"

GameEntity::GameEntity() :
    sprites(std::vector<TexturedRectangle*>()),
    position({x: 0, y: 0}),
    colliders(std::vector<Collider2D>())
{
    sprites.reserve(3);
    colliders.reserve(3);
}

GameEntity::GameEntity(const Vector2 &position, const size_t &spriteQuantity, const size_t &colliderQuantity) :
    sprites(std::vector<TexturedRectangle*>()),
    position(position),
    colliders(std::vector<Collider2D>())
{
    sprites.reserve(spriteQuantity);
    colliders.reserve(colliderQuantity);
}

void GameEntity::render() {
    for(int i = 0; i < sprites.size(); i++) {
        if(sprites[i] != NULL) {
            sprites[i]->render();
        }
    }
}

void GameEntity::drawCollidersHitboxes() {
    for(int i = 0; i < colliders.size(); i++) {
        colliders[i].drawHitbox();
    }
}

void GameEntity::update() {

}

void GameEntity::addTexturedRectangle(
        const char* filepath, 
        const Vector2 &dimensions, 
        const Vector2 &positionOffset
    ) 
{
    sprites.push_back(new TexturedRectangle(filepath, dimensions));
    sprites[sprites.size() - 1]->setRelativePosition(position, positionOffset);
}

void GameEntity::addTexturedRectangle(
        const char* filepath, 
        const SDL_Rect &rect 
    ) 
{
    sprites.push_back(new TexturedRectangle(filepath, {x: rect.w, y: rect.h}));
    sprites[sprites.size() - 1]->setAbsolutePosition({x: rect.x, y: rect.y});
}

void GameEntity::addCollider2D(const Vector2& dimensions, const Vector2 &positionOffset) {
    colliders.emplace_back(dimensions);
    colliders[colliders.size() - 1].setRelativePosition(position, positionOffset);
}


void GameEntity::addCollider2D(const SDL_Rect &rect) {
    colliders.emplace_back((Vector2){x: rect.w, y: rect.h});
    colliders[colliders.size() - 1].setAbsolutePosition({x: rect.x, y: rect.y});
}

void GameEntity::setPosition(const Vector2 &position) {
    this->position = position;
}

TexturedRectangle GameEntity::getTexturedRectangle(const size_t &index) const {
    return *sprites[index];
}

Collider2D GameEntity::getCollider2D(const size_t &index) const {
    return colliders[index];
}

GameEntity::~GameEntity() {
    for(int i = 0; i < sprites.size(); i++) {
        delete sprites[i];
    }
}
