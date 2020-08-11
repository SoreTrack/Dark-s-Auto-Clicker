#include <iostream>
#include <SDL.h>

bool quit = false; // Loop flag

SDL_Texture* texture = NULL; // TO EDIT
SDL_Window* window;
SDL_Surface* window_surface;
SDL_Renderer* renderer;

SDL_Rect rct;

void drawRect(int x, int y, int h, int w) // X axe | Y axe | Height | Widht
{
    rct.x = x;
    rct.y = y;
    rct.h = y;
    rct.w = w;
}

void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) // Red | Green | Blue | Alpha
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
        "Dark's Auto Clicker",             // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        500,                               // width, in pixels
        500,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags
    );
    if (window == NULL) {
        // In the case that the window could not be made...
        std::cout << "Failed to create an window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    window_surface = SDL_GetWindowSurface(window);
    if (!window_surface)
    {
        // In case window_surface could not be made...
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED
    );
    if (renderer == NULL) {
        // In the case that the renderer could not be made...
        std::cout << "Failed to create renderer\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    // Event handle
    SDL_Event e;

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User key input
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }
        rct.x = 250;
        rct.y = 150;
        rct.h = 200;
        rct.w = 200;
        setColor(255, 255, 255, 255); // Set Button Color

        SDL_RenderDrawRect(renderer, &rct);

        setColor(0, 0, 0, 255); // Set Button Color

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &rct);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window); // Destroy the window
    SDL_DestroyRenderer(renderer); // Destroy renderer
    SDL_Quit(); // Clean up

    return 0; // Close console
}
