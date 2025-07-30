#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"
#include "global.hpp"

TexturedRectangle::TexturedRectangle(const char* filepath, const Vector2 &dimensions) {
    this->texture = ResourceManager::getResourceManager()->getTexture(filepath);
    this->dimensions = dimensions;
}
void TexturedRectangle::render(const Vector2 &texturePosition) {
    SDL_Rect rect = {
        x: texturePosition.x,
        y: texturePosition.y,
        w: dimensions.x,
        h: dimensions.y
    };
    SDL_RenderCopy(mainRenderer, this->texture, NULL, &rect);
}

void TexturedRectangle::setDimension(const Vector2 &dimensions) {
    this->dimensions = dimensions;
}