#pragma once
#include <SDL2/SDL.h>
#include <unordered_map>

class ResourceManager {
//Attributes
private:
    static ResourceManager *resourceManager;
    std::unordered_map<const char*, SDL_Texture*> textures;
    
// Methods
private:
    ResourceManager();
public:
    static ResourceManager *getResourceManager();
    SDL_Texture *getTexture(const char* filepath);
};