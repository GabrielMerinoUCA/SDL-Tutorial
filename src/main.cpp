// local headers
#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"
#include "global.hpp"
#include "AnimatedSprite.hpp"
// C++ standard
#include <iostream>
// third party libs
#include <SDL2/SDL.h>



int main(int argc, char* argv[]) {
    /* VARIABLES */
    //create window datatype
    SDL_Window *window = NULL;
    // Create bool to know if game is running
    bool isGameRunning = true;
    // Event variable for event handling on main loop/sub loop
    SDL_Event event;
    /* if the image uses repeated colors, .gif is the better option. is lighter but a lil bit 
    slower and appears to have faulty compression but barely visible */
    int mouseX = 0, mouseY = 0;

    /* SOURCE CODE */
    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        LOG("Not initialized!!");
    }else LOG("SDL ready to go");

    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        LOG("failed to create window!");
    }

    // don't put any code that isn't declaration before this unless you know it doesn't use the renderer
    mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TexturedRectangle rect1("assets/images/stickboy.bmp", {150,150,100,100});
    TexturedRectangle rect2("assets/images/stickboy.bmp", {0,100,100,100});

    while(isGameRunning) {
        SDL_GetMouseState(&mouseX, &mouseY);

        //1: Get input
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                isGameRunning = false;
            }
            if(event.button.button == SDL_BUTTON_LEFT) {
                // the most ideal way to do this will be to just use the function
                // But with OOP, it will be for the function to accept SDL_Rect since it's less data.
                if(rect2.isColliding(rect1)){
                    LOG("Collided!");
                }
            }
        }
        //2: handle game logic
        rect2.rect.x = mouseX;
        rect2.rect.y = mouseY;

        //3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(mainRenderer);

        SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
        rect1.render();
        rect2.render();
        
        SDL_RenderPresent(mainRenderer);
    }
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}