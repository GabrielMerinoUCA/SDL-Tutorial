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
    std::function<void()> renderCallback;
    std::function<void()> updateCallback;
    // Should be a vector2
    int mouseX, mouseY;
    Uint32 deltaTime;
    Uint32 frameRate_MS;
    SDLApp();

// Methods
public:
    // be advised that default constructor exists with no params, it could lead to bad init if called.
    SDLApp(const char* title, const SDL_Rect &windowSize, const float &frameCap);
    ~SDLApp();

    void setEventCallback(std::function<void(SDL_Event&)> eventCallback);
    void setRenderCallback(std::function<void()> renderCallback);
    void setUpdateCallback(std::function<void()> updateCallback);
    /**
     * set the frame rate in milliseconds
     * @param frameCap is the target frame rate cap in FPS i.e 60 FPS 
     */
    void setFrameRate_MS(const float &frameCap);
    void runLoop();
    void stopAppLoop();
    int getMouseX() const;
    int getMouseY() const;

};