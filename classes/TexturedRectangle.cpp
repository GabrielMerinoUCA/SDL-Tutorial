#include <SDL2/SDL.h>
#include "../headers/TexturedRectangle.hpp"

TexturedRectangle::TexturedRectangle(const char *filepath, SDL_Renderer *renderer, SDL_Rect rect) {
    SDL_Surface *surface = SDL_LoadBMP(("../%s", filepath));
    this->renderer = renderer;
    this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    this->rect = rect;
    SDL_FreeSurface(surface);
}
TexturedRectangle::TexturedRectangle(const char *filepath, SDL_Renderer *renderer) {
    SDL_Surface *surface = SDL_LoadBMP(("../%s", filepath));
    this->renderer = renderer;
    this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    SDL_FreeSurface(surface);
}
TexturedRectangle::~TexturedRectangle() {
    SDL_DestroyTexture(this->texture);
}
void TexturedRectangle::render() {
    SDL_RenderCopy(this->renderer, this->texture, NULL, &this->rect);
}
