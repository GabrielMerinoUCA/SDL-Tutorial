// local headers
#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"
#include "global.hpp"
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
    

    /* SOURCE CODE */
    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        LOG("Not initialized!!");
    }else LOG("SDL ready to go");

    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        LOG("failed to create window!");
        return -1;
    }

    mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TexturedRectangle rect1 = TexturedRectangle(
        "assets/images/image.bmp",
        {0,0,640,330}
    );
    TexturedRectangle rect2 = TexturedRectangle(
        "assets/images/image.bmp",
        {0,100,640,330}
    );
    TexturedRectangle rect3 = TexturedRectangle(
        "assets/images/image.bmp",
        {0,200,640,330}
    );

    //1: window 
    while(isGameRunning) {
        //1: Get input
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                isGameRunning = false;
            }
        }
        //2: handle game logic

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
        rect3.render();

        SDL_RenderPresent(mainRenderer);
    }
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}