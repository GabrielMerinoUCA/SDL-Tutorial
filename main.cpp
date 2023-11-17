// C++ standard
#include <iostream>

// third party libs
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    
    //create window datatype
    SDL_Window *window = nullptr; // pointer because windows are dynamic, need more than stack, and complex.
    //btw, always initialize variables, even if as null values (obviously not literally null for all cases)

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }
    else {
        std::cout<<"SDL ready to go\n";
    }

    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 500, 500, SDL_WINDOW_SHOWN); // creates on heap and returns a pointer

    if(window == NULL) {
        std::cout<<"failed to create window"<<std::endl;
    }
    
    // because the program runs fast, the window will be destroyed before we realize, so we delay the execution so
    // we can see it actually works
    SDL_Delay(10000);


    //release memory
    SDL_DestroyWindow(window);

    SDL_Quit(); // shutdown all SDL subsystems
    return 0;
}