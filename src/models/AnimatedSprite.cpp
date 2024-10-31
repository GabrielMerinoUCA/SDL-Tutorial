#include "global.hpp"
#include "ResourceManager.hpp"
#include "AnimatedSprite.hpp"
#include <SDL2/SDL.h>

AnimatedSprite::AnimatedSprite(const char* filepath) {
    this->textureSprite = ResourceManager::getResourceManager()->getTexture(filepath);
}

void AnimatedSprite::draw(const SDL_Rect &dest) {
    this->dest = dest;
}

void AnimatedSprite::playFrame(const SDL_Rect &source, const int &frame) {
    this->source = source;
    this->source.x = source.x + source.w * frame;
}

void AnimatedSprite::render() {
    SDL_RenderCopy(mainRenderer, this->textureSprite, &this->source, &this->dest);
}