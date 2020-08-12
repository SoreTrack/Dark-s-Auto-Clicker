#include <iostream>
#include "app.h"

App* app = nullptr;

int main(int argc, char* args[])
{
    app = new App();

    app->App::init("Dark's Auto Clicker ALPHA v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 400);

    while (app->running()) {
        app->App::handleEvent();
        app->App::GUI();
        app->App::render();
        app->App:: clicker();
    }

    app->App::clean();
    app->App::~App();

    app = nullptr;
    delete app;

    return 0;
}
