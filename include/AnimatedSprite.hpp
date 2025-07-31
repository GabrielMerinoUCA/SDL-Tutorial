#pragma once
#include <SDL2/SDL.h>

class AnimatedSprite {
// Attributes
private:
    SDL_Rect source;
    SDL_Rect dest;
    SDL_Texture *textureSprite;
    
// Methods
public:
    AnimatedSprite(const char *filepath);
    void draw(const SDL_Rect &dest);
    //perhaps the current frame count should be handled by this class
    void playFrame(const SDL_Rect &source, const int &frame);
    void update();
    void render();
};