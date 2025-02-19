// local headers
#include "TexturedRectangle.hpp"
#include "global.hpp"
#include "SDLApp.hpp"
// third party libs
#include <SDL2/SDL.h>

TexturedRectangle *rect1, *rect2;
SDLApp *myApp;

void handleEvent(SDL_Event &event);
void render();

int main(int argc, char* argv[]) {
    /* VARIABLES */
    myApp = new SDLApp("SDL Tutorial", {0, 0, 640, 480});
    myApp->setEventCallback(handleEvent);
    myApp->setRenderCallback(render);
    rect1 = new TexturedRectangle("assets/images/stickboy.bmp", {150,150,100,100});
    rect2 = new TexturedRectangle("assets/images/stickboy.bmp", {0,100,100,100});

    myApp->runLoop();    
    delete myApp;
}


void render() {
    
    rect2->rect.x = myApp->getMouseX();
    rect2->rect.y = myApp->getMouseY();

    rect1->render();
    rect2->render();
}

void handleEvent(SDL_Event &event) {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            myApp->stopAppLoop();
        }
        if(event.button.button == SDL_BUTTON_LEFT) {
            // the most ideal way to do this will be to just use the function
            // But with OOP, it will be for the function to accept SDL_Rect since it's less data.
            if(rect2->isColliding(*rect1)){
                LOG("Collided!");
            }
        }
    }
}