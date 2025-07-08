#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"
#include "global.hpp"

TexturedRectangle::TexturedRectangle(const char* filepath, const SDL_Rect &rect) {
    this->texture = ResourceManager::getResourceManager()->getTexture(filepath);
    this->rect = rect;
}
void TexturedRectangle::render() {
    SDL_RenderCopy(mainRenderer, this->texture, NULL, &this->rect);
}

bool TexturedRectangle::isColliding(const TexturedRectangle &obj) {
    return SDL_HasIntersection(&(this->rect), &obj.rect);
}

void TexturedRectangle::setPosition(const int &x, const int &y) {
    this->rect.x = x;
    this->rect.y = y;
}

void TexturedRectangle::setDimension(const int &w, const int &h) {
    this->rect.w = w;
    this->rect.h = h;
}