// local headers
#include "./headers/TexturedRectangle.hpp"
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
    // This allows you to manipulate graphics on an efficient manner. NOT COMPATIBLE WITH SURFACES
    SDL_Renderer *renderer = NULL;
    /* if the image uses repeated colors, .gif is the better option. is lighter but a lil bit 
    slower and appears to have faulty compression but barely visible */

    /* SOURCE CODE */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }else std::cout<<"SDL ready to go\n";

    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout<<"failed to create window!"<<std::endl;
        return -1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TexturedRectangle rect("image.bmp", renderer, {0,0,640,330});

    //1: window 
    while(isGameRunning) {
        //1: Get input
        while(SDL_PollEvent(&event)) {
            // there aren't many events, if statement might be more optimal
            switch(event.type) {
                case SDL_QUIT:
                    isGameRunning = false;
                    break;      
                default:
                    break;
            }
        }
        
        //2: handle game logic

        //3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        rect.render();

        SDL_RenderPresent(renderer);
    }
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}
