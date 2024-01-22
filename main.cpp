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
    SDL_Surface *surface = SDL_LoadBMP("./waves.bmp");
    SDL_Surface *surfaceR = SDL_LoadBMP("./wavesR.bmp");
    SDL_Rect    rectangle[8] = {
        // top left to bottom right
        {0, 0, surface->w, surface->h}, // og
        {-surface->w, 0, surface->w, surface->h}, // left
        {0, -surface->h, surface->w, surface->h}, // up
        {-surface->w, -surface->h, surface->w, surface->h}, // opposite
        
        // top right to bottom left
        {0, 0, surface->w, surface->h}, // og
        {surface->w, 0, surface->w, surface->h}, // right
        {0, -surface->h, surface->w, surface->h}, // top
        {surface->w, -surface->h, surface->w, surface->h} // opposite
    };

    SDL_Texture *waveTexture = NULL;
    SDL_Texture *waveTextureR = NULL;

    /* SOURCE CODE */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){ // this can be optimized by just using SDL_Init, this example is good for debugging.
        std::cout<<"Not initialized!! \n"<<SDL_GetError()<< "\n";
    }else std::cout<<"SDL ready to go\n";
    
    window = SDL_CreateWindow("SDL Tutorial", 0, 0, surface->w, surface->h, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout<<"failed to create window!"<<std::endl;
        return -1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // You create a texture using pixel info from surface with renderer as the "engine"
    waveTexture = SDL_CreateTextureFromSurface(renderer, surface);
    waveTextureR = SDL_CreateTextureFromSurface(renderer, surfaceR);
    SDL_FreeSurface(surface);
    SDL_FreeSurface(surfaceR);
    //SDL_SetTextureBlendMode(waveTexture, SDL_BLENDMODE_ADD);

    //1: window 
    while(isGameRunning) {
        //1: Get input
        while(SDL_PollEvent(&event)) {
            // there aren't many events, if statement might be more optimal
            switch(event.type) {
                case SDL_QUIT:
                    isGameRunning = false;
                    break;      
                case SDL_KEYDOWN:
                    if(event.key.keysym.scancode == SDL_SCANCODE_1) {
                        SDL_SetTextureBlendMode(waveTextureR, SDL_BLENDMODE_ADD);
                    }   
                    else if(event.key.keysym.scancode == SDL_SCANCODE_2) {
                        SDL_SetTextureBlendMode(waveTextureR, SDL_BLENDMODE_BLEND);
                    }   
                    else if(event.key.keysym.scancode == SDL_SCANCODE_3) {
                        SDL_SetTextureBlendMode(waveTextureR, SDL_BLENDMODE_MOD);
                    }   
                    else if(event.key.keysym.scancode == SDL_SCANCODE_0) {
                        SDL_SetTextureBlendMode(waveTextureR, SDL_BLENDMODE_NONE);
                    }   
                    break;
                default:
                    break;
            }
        }
        
        //2: handle game logic
        for(int i = 0; i < (sizeof(rectangle) / sizeof(rectangle[0])) / 2; i++) {
            rectangle[i].x += surface->w / surface->w;
            rectangle[i].y += surface->h / surface->w;
            rectangle[i+4].x -= surface->w / surface->w;
            rectangle[i+4].y += surface->h / surface->w;
        }
        if(rectangle[0].x >= surface->w || rectangle[0].y >= surface->h) {
            rectangle[0].x = 0; rectangle[0].y = 0;
            rectangle[1].x = -surface->w; rectangle[1].y = 0;
            rectangle[2].x = 0; rectangle[2].y = -surface->h;
            rectangle[3].x = -surface->w; rectangle[3].y = -surface->h;
        }
        if(rectangle[4].x <= -surface->w || rectangle[4].y >= surface->h) {
            rectangle[4].x = 0; rectangle[4].y = 0;
            rectangle[5].x = surface->w; rectangle[5].y = 0;
            rectangle[6].x = 0; rectangle[6].y = -surface->h;
            rectangle[7].x = surface->w; rectangle[7].y = -surface->h;
        }
        //3: Clear and render.
        // Stablish how you want the screen to look on refresh, realistically, you'll use a different
        // variable called background or something (I assume).
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        // Restart the whole screen according to the current renderer, here it's color but I assume
        // it could also be images.
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 5, 5, 100, 120);
        // Instead of drawing a rectangle, we create a texture and use rectangle
        // to define it's outline/size
        
        SDL_RenderCopy(renderer, waveTexture, NULL, &rectangle[0]);
        SDL_RenderCopy(renderer, waveTexture, NULL, &rectangle[1]);
        SDL_RenderCopy(renderer, waveTexture, NULL, &rectangle[2]);
        SDL_RenderCopy(renderer, waveTexture, NULL, &rectangle[3]);
        SDL_RenderCopy(renderer, waveTextureR, NULL, &rectangle[4]);
        SDL_RenderCopy(renderer, waveTextureR, NULL, &rectangle[5]);
        SDL_RenderCopy(renderer, waveTextureR, NULL, &rectangle[6]);
        SDL_RenderCopy(renderer, waveTextureR, NULL, &rectangle[7]);

        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    }
    // always a good practice to destroy pointers to leave ram clear of garbage values
    SDL_DestroyTexture(waveTexture);
    SDL_DestroyTexture(waveTextureR);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
