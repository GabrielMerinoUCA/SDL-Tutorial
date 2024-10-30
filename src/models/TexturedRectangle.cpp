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
