// local headers
#include "global.hpp"
#include "SDLApp.hpp"
#include "GameEntity.hpp"
// third party libs
#include <SDL2/SDL.h>

static const float FRAME_CAP = 60.0f;
static GameEntity *obj1, *obj2;
static SDLApp *myApp;

void handleEvent(SDL_Event &event);
void render();
void update();

int main(int argc, char* argv[]) {
    myApp = new SDLApp("SDL Tutorial", {x: 0, y: 0, WINDOW_WIDTH, WINDOW_HEIGHT}, FRAME_CAP);
    myApp->setEventCallback(handleEvent);
    myApp->setRenderCallback(render);
    myApp->setUpdateCallback(update);

    obj1 = new GameEntity({x: 150, y: 150}, 1, 2);
    obj1->addTexturedRectangle("assets/images/stickboy.bmp", {x: 100, y: 100}, {0, 0});
    obj1->addCollider2D({x: 100, y: 100}, {0, 0});
    obj1->addCollider2D({x: 50, y: 50}, {25, 25});

    obj2 = new GameEntity({x: 0, y: 100}, 1, 1);
    obj2->addTexturedRectangle("assets/images/stickboy.bmp", {x: 100, y: 100}, {0, 0});
    obj2->addCollider2D({x: 100, y: 100}, {0, 0});

    myApp->runLoop();
    delete obj1;
    delete obj2;
    delete myApp;
}

// handles movement of objects or their updatas in general terms
void update() {
    obj2->setPosition({myApp->getMouseX(), myApp->getMouseY()});
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

    obj1->setPosition({x, y});

    obj1->update();
    obj2->update();
}

// the render callback tells the app which objects we want to render
void render() {
    obj1->render();
    obj2->render();
    obj1->drawCollidersHitboxes();
    obj2->drawCollidersHitboxes();
}

void handleEvent(SDL_Event &event) {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            myApp->stopAppLoop();
        }
        if(event.button.button == SDL_BUTTON_LEFT) {
            // the most ideal way to do this will be to just use the function
            // But with OOP, it will be for the function to accept SDL_Rect since it's less data.
            if(obj2->getCollider2D(0).isColliding(obj1->getCollider2D(0))){
                LOG("Collided!");
            }
        }
    }
}