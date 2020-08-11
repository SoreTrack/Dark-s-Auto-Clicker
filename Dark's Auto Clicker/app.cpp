#include "app.h"
#include "timer.h"

App::App() {};
App::~App() {};

Timer* timer = nullptr;

void App::init(const char* title, int xpos, int ypos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialised! ...\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		if (window)
		{
			std::cout << "Window Successfully Created! ...\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Successfully Created! ...\n";
		}

		isRunning = true;
	} else {
		isRunning = false;
	}
}

void App::handleEvent()
{
	timer = new Timer();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			
			switch (event.key.keysym.sym)
			{
				case SDLK_f:
					bool timeFinish = timer->getStop();
					bool started = timer->isStarted();
					if (started == true) { // Verify is the timer is started
						timer->timeLoop();
						if (timeFinish == true) {
							timer->stopTimer();

							std::cout << "You said f*ck you to the program.\n";
							std::cout << "The program is angry.\n";
							std::cout << "The program will closed because you said f*ck you to it.\n";
							isRunning = false;
						}
					}
					else { // Start the timer
						timer->startTimer(5000);
						timer->timeLoop();
					}
					break;
			}
		}
	}
	
	delete timer;
}

void App::update()
{}

void App::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool App::running()
{
	return isRunning;
}

void App::clicker()
{
	if (autoClick)
	{
		FreeConsole();

		int i, x, y;

		{
			x = 1000;
			y = 1000;
			SetCursorPos(x, y);
			Sleep(1);

		}

		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}