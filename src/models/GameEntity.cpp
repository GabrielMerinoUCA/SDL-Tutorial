#include "GameEntity.hpp"
#include <SDL2/SDL.h>

GameEntity::GameEntity() {
    sprite = NULL;
}

GameEntity::GameEntity(const char* filepath, const SDL_Rect &rect) {
    this->sprite = new TexturedRectangle(filepath, rect);
}

// Honestly, this just looks redundant
void GameEntity::render() {
    if(this->sprite != NULL) {
        sprite->render();
    }
}

TexturedRectangle &GameEntity::getTexturedRectangle() const {
    return *sprite;
}

GameEntity::~GameEntity() {}
