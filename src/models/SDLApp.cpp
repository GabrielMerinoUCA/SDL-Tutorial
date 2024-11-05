#include "SDLApp.hpp"
#include "global.hpp"
#include <SDL2/SDL.h>
#include <functional>

SDLApp::SDLApp(const char* title, const SDL_Rect &windowSize) {
    this->isGameRunning = true;
    this->mouseX = 0;
    this->mouseY = 0;

    // initialize video related sdl functions
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        LOG("Not initialized!");
    } else {LOG("SDL ready to go");}

    // window creation
    this->window = SDL_CreateWindow(
        title, 
        windowSize.x, 
        windowSize.y, 
        windowSize.w, 
        windowSize.h, 
        SDL_WINDOW_SHOWN
    );
    // validate window creation
    if(this->window == NULL) {
        LOG("Failed to create window!");
    }

    mainRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

SDLApp::~SDLApp() {
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyWindow(this->window);
    SDL_Quit(); 
}

void SDLApp::setEventCallback(std::function<void(SDL_Event&)> eventCallback) {
    this->eventCallback = eventCallback;
}

void SDLApp::setRenderCallback(std::function<void(void)> renderCallback) {
    this->renderCallback = renderCallback;
}

void SDLApp::runLoop() {
    while(isGameRunning) {

        eventCallback(this->event);

        SDL_GetMouseState(&(this->mouseX), &(this->mouseY));

        // by adding this here, we don't have to worry about it on our custom render functions.
        //3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(mainRenderer);

        renderCallback();
        SDL_RenderPresent(mainRenderer);

    }
}

void SDLApp::stopAppLoop() {
    this->isGameRunning = false;
}

int SDLApp::getMouseX() const{
    return this->mouseX;
}

int SDLApp::getMouseY() const{
    return this->mouseY;
}