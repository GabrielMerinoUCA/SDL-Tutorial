#include "ResourceManager.hpp"
#include "global.hpp"
#include <SDL2/SDL.h>
#include <iostream>

ResourceManager::ResourceManager(){
}

ResourceManager *ResourceManager::getResourceManager() {
    if(ResourceManager::resourceManager == NULL) { // mike uses a different code that is kinda sus so I changed it a bit
        ResourceManager::resourceManager = new ResourceManager();
    }
    return ResourceManager::resourceManager;
}

SDL_Texture *ResourceManager::getTexture(const char* filepath) {
    auto search = textures.find(filepath);
    // there is no loop 'cause it is on the operator overload i assume
    if(search == textures.end()) { // if when iterating on the texture list, we reach the end, that means that the texture doesn't exists.
        std::cout<<"should be once"<<std::endl;
        SDL_Surface *surface = SDL_LoadBMP(filepath);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
        textures.insert(std::make_pair(filepath, texture));
        SDL_FreeSurface(surface);
    }
    return textures[filepath];
}
// this looks ridiculous ngl.
ResourceManager *ResourceManager::resourceManager;