// C++ standard
#include <iostream>
#include <typeinfo>
// third party libs
#include <SDL2/SDL.h>

void setPixel(SDL_Surface *surface, Uint16 mouseX, Uint16 mouseY, Uint8 r, Uint8 g, Uint8 b) {
    SDL_LockSurface(surface);
    Uint8 *pixelArray = (Uint8)surface->pixels;

    SDL_UnlockSurface(surface);
}

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
    /* A surface is like a canvas, we can draw in it (put pixel information in it)
    and we can we can manage the data of the pixel cluster using the 
    atributes */
    SDL_Surface *screen = NULL;
    SDL_Surface *image = NULL;

    int mouseX = 0, mouseY = 0;

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
    screen = SDL_GetWindowSurface(window); // could be assigned at the beginning
    // this function creates a canvas that is preloaded with an image.bmp you chose from your directory
    // it needs to be assigned to a variable 'cause it uses heap, we free memory later to avoid memory leak.
    image = SDL_LoadBMP("image.bmp");
    /* remember, surfaces are like surfaces that have a literal block of pixel + their info in top of them. this block
     of pixels can be copied and given to another surface. This is what we are doing here.
     "Get the pixel info from this canvas and put it in this other canvas" the other params are unknown for know
     this is literally lik e a "strcpy()".
    */
    SDL_BlitSurface(image, NULL, screen, NULL);
    //once we use the pixel block, we need to delete it from heap. Use this for that. Just like free()
    SDL_FreeSurface(image);
    // This function will render on the actual screen the pixel info stored on its attribute.
    SDL_UpdateWindowSurface(window); 
    while(isGameRunning) {
        SDL_GetMouseState(&mouseX,& mouseY);
        while(SDL_PollEvent(&event)) {
            // there aren't many events, if statement might be more optimal
            switch(event.type) {
                case SDL_QUIT:
                    isGameRunning = false;
                    break;
                /* button has info of the mouse event itself while the second button 
                has info of which button triggered the event */
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        std::cout<<mouseX<<", "<<mouseY<<std::endl;
                    }
                    break;
                default:
                    break;
            }
            // it seems like this could allow us to decouple the inputs from the other events. But, do we want to?
            // Ok so Uint8 is literally just a string. however, trying to get a string out of it is impossible.
            // because the values are 0 and 1, not ascii letters.
            if(state[SDL_SCANCODE_RIGHT] == 1) {
                std::cout<<"right key pressed"<<std::endl;
                // Prevents pixel data of surface from being altered from another part of the code
                // btw this is not necessary if you don't make changes from another part of the code, 
                //leave it there as good practice and remove it later if not needed
                SDL_LockSurface(screen);
                /* pixels is a void pointer, here it acts like an array. memset will fill a specific amount of 
                times(3rd arg) certain value (2nd arg) such array (1st arg). 255 is white(only black to white)
                 'h' is height, and pitch is width but accessed in a faster way (considers memory alignment and padding) */
                SDL_memset(screen->pixels, 255, screen->h * screen->pitch); // pitch is width, but faster.
                // unlock or else you won't be able to lock it or change it again
                SDL_UnlockSurface(screen);
                
            } // idk but maybe we need to take this out of the poll event loop
        }
        // This is kinda like double buffering since we first make all the changes before drawing.
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
