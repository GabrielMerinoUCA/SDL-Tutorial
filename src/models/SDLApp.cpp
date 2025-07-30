#include "SDLApp.hpp"
#include "global.hpp"
#include <SDL2/SDL.h>

SDLApp::SDLApp(const char* title, const SDL_Rect &windowSize, const float & frameCap) {
    // Attributes 
    this->isGameRunning = true;
    this->mouseX = 0;
    this->mouseY = 0;
    this->deltaTime = 0;
    this->setFrameRate_MS(frameCap);

    // initialize video related sdl functions
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        LOG("Not initialized!");
    } else {LOG("SDL ready to go");}

    // window creation, should probably change SDL_WINDOW_SHOWN to other like resizable
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

void SDLApp::setRenderCallback(std::function<void()> renderCallback) {
    this->renderCallback = renderCallback;
}

void SDLApp::setUpdateCallback(std::function<void()> updateCallback) {
    this->updateCallback = updateCallback;
}

void SDLApp::setFrameRate_MS(const float &frameCap) {
    // where 1000 converts our framecap to milliseconds.
    this->frameRate_MS = (1.0f/frameCap) * 1000.0f;
}

void SDLApp::runLoop() {
    Uint32 previousTime = 0;
    while(isGameRunning) {
        // previous time will take current time but by the time it is used, it would have become
        // previous time.
        previousTime = SDL_GetTicks();

        // in the future, it might be a good idea to use different threads for events and render
        eventCallback(this->event);

        SDL_GetMouseState(&(this->mouseX), &(this->mouseY));

        updateCallback();

        // by adding this here, we don't have to worry about it on our custom render functions.
        // 3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(mainRenderer);

        renderCallback();
        SDL_RenderPresent(mainRenderer);
        deltaTime = SDL_GetTicks() - previousTime;
        if(deltaTime < frameRate_MS) {
            /* 
                Delay essentially limits the game to a specific max framerate or at least tries to like in 
                minecraft. so if the delay is each 16.66... ms or 60 FPS, the loop wil take as long as it has
                to, and then wait 16ms to continue. In this case, we make it always be 16ms. If the logic took
                4ms, and the expected time is 16ms, then we have to delay 16-4ms.
            */
            SDL_Delay(frameRate_MS - deltaTime);
        }
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