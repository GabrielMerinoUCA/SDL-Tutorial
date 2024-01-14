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
    // Get the live state (which key is pressed) of the keyboard
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // This allows you to manipulate graphics on an efficient manner. NOT COMPATIBLE WITH SURFACES
    SDL_Renderer *renderer = NULL;
    SDL_Rect rectangle;

    /* SOURCE CODE */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }else std::cout<<"SDL ready to go\n";
    
    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout<<"failed to create window!"<<std::endl;
        return -1;
    }
    int x=0,y=0;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    rectangle.h = 50;
    rectangle.w = 100;
    rectangle.x = 200;
    rectangle.y = 200;
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
            if (state[SDL_SCANCODE_RIGHT] == 1) {
                x++;
                y++;
            }
        }
        
        //2: handle game logic

        //3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 5+x,5,100+x,120);
        SDL_RenderDrawRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
