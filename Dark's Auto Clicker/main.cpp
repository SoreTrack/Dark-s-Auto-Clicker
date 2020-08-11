#include <iostream>
#include "app.h"

App* app = nullptr;

int main(int argc, char* args[])
{
    app = new App();

    app->init("Dark's Auto Clicker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

    while (app->running()) {
        app->handleEvent();
        app->update();
        app->render();
        app->clicker();
    }

    app->clean();

    return 0;
}
