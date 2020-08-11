#include <iostream>
#include "app.h"

App* app = nullptr;

int main(int argc, char* args[])
{
    app = new App();

    app->init("Dark's Auto Clicker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 400);

    while (app->running()) {
        app->handleEvent();
        app->GUI();
        app->render();
        app->clicker();
    }

    app->clean();

    return 0;
}
