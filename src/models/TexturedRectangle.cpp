#include "TexturedRectangle.hpp"

TexturedRectangle::TexturedRectangle(
        const char *filepath, 
        const Vector2 &dimensions 
    ) :
    texture(ResourceManager::getResourceManager()->getTexture(filepath)),
    Transform2D(dimensions)
{ }

void TexturedRectangle::render() {
    SDL_Rect rect;
    if(this->isRelativePositionSet()) {
        rect = {
            x: relativePosition->x + positionOffset.x,
            y: relativePosition->y + positionOffset.y,
            w: dimensions.x,
            h: dimensions.y
        };
        SDL_RenderCopy(mainRenderer, this->texture, NULL, &rect);
        return;
    }
    rect = {
        x: absolutePosition.x,
        y: absolutePosition.y,
        w: dimensions.x,
        h: dimensions.y
    };
    SDL_RenderCopy(mainRenderer, this->texture, NULL, &rect);
}