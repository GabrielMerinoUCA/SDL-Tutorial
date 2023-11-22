// C++ standard
#include <iostream>

// third party libs
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    
    /* VARIABLES */

    //create window datatype
    SDL_Window *window = nullptr;
    // Create bool to know if game is running
    bool isGameRunning = true;
    // Event variable for event handling on main loop/sub loop
    SDL_Event event;


    /* SOURCE CODE */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }else std::cout<<"SDL ready to go\n";
    

    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 500, 500, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout<<"failed to create window!"<<std::endl;
        return -1;
    }
    while(isGameRunning) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    isGameRunning = false;
                    break;
                case SDL_MOUSEMOTION:
                    std::cout<<"Mouse position: "<<event.motion.x<<" "<<event.motion.y<<std::endl;
                    break;
                case SDL_KEYDOWN:
                    std::cout<<"key has been pressed: ";
                    if(event.key.keysym.scancode == SDL_SCANCODE_A) {
                        std::cout<<"Key A"<<std::endl;
                    }
                    break; 
                default:
                    std::cout<<"Unhandled event... What?"<<std::endl;
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
