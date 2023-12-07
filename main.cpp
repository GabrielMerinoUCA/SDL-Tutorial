// C++ standard
#include <iostream>
#include <typeinfo>
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
    // Get the live state (which key is pressed) of the keyboard
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    /* A surface is like a canvas, we can draw in it (put pixel information in it)
    and we can we can manage the data of the pixel cluster using the 
    atributes */
    SDL_Surface *screen; // NEW
    SDL_Surface *image; // NEW

    /* SOURCE CODE */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }else std::cout<<"SDL ready to go\n";
    
    window = SDL_CreateWindow("SDL Tutorial", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout<<"failed to create window!"<<std::endl;
        return -1;
    }

    // Here you are getting the canvas of the window. If you want to change the BG, you'll need this.
    screen = SDL_GetWindowSurface(window);
    // this function creates a canvas that is preloaded with an image.bmp you chose from your directory
    // it needs to be assigned to a variable 'cause it uses heap, we free memory later to avoid memory leak.
    image = SDL_LoadBMP("image.bmp");
    /* remember, surfaces are like surfaces that have a literal block of pixel + their info in top of them. this block
     of pixels can be copied and given to another surface. This is what we are doing here.
     "Get the pixel info from this canvas and put it in this other canvas" the other params are unknown for know
     this is literally like a "strcopy()".
    */
    SDL_BlitSurface(image, NULL, screen, NULL);
    //once we use the pixel block, we need to delete it from heap. Use this for that. Just like free()
    SDL_FreeSurface(image);
    
    SDL_UpdateWindowSurface(window); // NEW

    while(isGameRunning) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    isGameRunning = false;
                    break;
                default:
                    break;
            }
            // it seems like this could allow us to decouple the inputs from the other events. But, do we want to
            // Ok so Uint8 is literally just a string. however, trying to get a string out of it is impossible.
            // because the values are 0 and 1, not ascii letters.
            if(state[SDL_SCANCODE_RIGHT] == 1) {
                std::cout<<"right key pressed"<<std::endl;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
