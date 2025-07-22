// local headers
#include "global.hpp"
#include "SDLApp.hpp"
#include "GameEntity.hpp"
// third party libs
#include <SDL2/SDL.h>

// for the temporal thingy
static int speed = 10;

static const float FRAME_CAP = 60.0f;
static GameEntity *obj1, *obj2;
static SDLApp *myApp;

void handleEvent(SDL_Event &event);
void render();

int main(int argc, char* argv[]) {
    /* VARIABLES */
    myApp = new SDLApp("SDL Tutorial", {x: 0, y: 0, WINDOW_WIDTH, WINDOW_HEIGHT}, FRAME_CAP);
    myApp->setEventCallback(handleEvent);
    myApp->setRenderCallback(render);
    obj1 = new GameEntity(
        "assets/images/stickboy.bmp", 
        {
            x: 150,
            y: 150,
            w: 100,
            h: 100
        }
    );
    obj2 = new GameEntity(
        "assets/images/stickboy.bmp",
        {
            x: 0, 
            y: 100,
            w: 100,
            h: 100
        }
    );

    myApp->runLoop();
    delete obj1;
    delete obj2;
    delete myApp;
}


void render() {
    TexturedRectangle &rect1 = obj2->getTexturedRectangle(); // a lil dangerous but whatever. (reassignment possible)
    TexturedRectangle &rect2 = obj1->getTexturedRectangle();
    // doing it this way makes it more readable documentation wise.
    rect1.setPosition(myApp->getMouseX(), myApp->getMouseY());

    // FOR DEMONSTRATION PURPOSES ONLY, NOT TO BE USED IN ANY REAL LIFE SCENARIO
    static int x = 0, y = 0;
    static bool up = true, right = true;

    if(y == 0) {
        up = false;
    }
    else if(y == WINDOW_HEIGHT - 1) {
        up = true;
    }
    if(x == 0) {
        right = true;
    }
    else if(x == WINDOW_WIDTH - 1) {
        right = false;
    }
    
    if(up) {
        y--;
    }else{
        y++;
    }
    if(right) {
        x++;
    }else{
        x--;
    }

    rect2.setPosition(x,y);
    
    obj1->render();
    obj2->render();
}

void handleEvent(SDL_Event &event) {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            myApp->stopAppLoop();
        }
        if(event.button.button == SDL_BUTTON_LEFT) {
            // the most ideal way to do this will be to just use the function
            // But with OOP, it will be for the function to accept SDL_Rect since it's less data.
            if(obj2->getTexturedRectangle().isColliding(obj1->getTexturedRectangle())){
                LOG("Collided!");
            }
        }
    }
}