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

    int frameNumber = 0;
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

    // don't put any code that isn't declaration before this unless you know it doesn't use the renderer
    mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    AnimatedSprite marioSprite("assets/images/MarioSpriteSheet.bmp");
    marioSprite.draw({100, 100, 32*4, 34*4});// this rect defines the size of the image on screen.

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

        marioSprite.playFrame({16, 0, 16, 17}, frameNumber);// this is the size of the inner frame, the iterator.
        marioSprite.render();
        frameNumber++;
        if(frameNumber>=3){
            frameNumber=0;
        }
        SDL_Delay(100);

        SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);

        SDL_RenderPresent(mainRenderer);
    }
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}