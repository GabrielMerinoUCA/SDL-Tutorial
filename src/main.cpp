// local headers
#include "global.hpp"
#include "SDLApp.hpp"
#include "GameEntity.hpp"
// third party libs
#include <SDL2/SDL.h>

GameEntity *rect1, *rect2;
SDLApp *myApp;

void handleEvent(SDL_Event &event);
void render();

int main(int argc, char* argv[]) {
    /* VARIABLES */
    myApp = new SDLApp("SDL Tutorial", {0, 0, 640, 480});
    myApp->setEventCallback(handleEvent);
    myApp->setRenderCallback(render);
    rect1 = new GameEntity("assets/images/stickboy.bmp", {150,150,100,100});
    rect2 = new GameEntity("assets/images/stickboy.bmp", {0,100,100,100});

    myApp->runLoop();
    delete rect1;
    delete rect2;
    delete myApp;
}


void render() {
    TexturedRectangle &rect = rect2->getTexturedRectangle(); // a lil dangerous but whatever. (reassignment possible)
    // doing it this way makes it more readable documentation wise.
    rect.setPosition(myApp->getMouseX(), myApp->getMouseY());

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
            if(rect2->getTexturedRectangle().isColliding(rect1->getTexturedRectangle())){
                LOG("Collided!");
            }
        }
    }
}