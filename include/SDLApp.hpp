#pragma once
#include <SDL2/SDL.h>
#include <functional>

class SDLApp{
    // attributes
    private:
    SDL_Window *window;
    SDL_Event event;
    bool isGameRunning;
    std::function<void(SDL_Event&)> eventCallback;
    std::function<void(void)> renderCallback;
    int mouseX, mouseY;


    // methods
    public:
    // be advised that default constructor exists with no params, it could lead to bad init if called.
    SDLApp(const char* title, const SDL_Rect &windowSize);
    ~SDLApp();

    void setEventCallback(std::function<void(SDL_Event&)> eventCallback);
    void setRenderCallback(std::function<void(void)> renderCallback);
    void runLoop();
    void stopAppLoop();
    int getMouseX() const;
    int getMouseY() const;

};