#pragma once
#include <SDL2/SDL.h>
#include <iostream>

// MACROS:

#define LOG(x) std::cout<<x<<"\n"

// CONSTS: 

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern SDL_Renderer *mainRenderer;