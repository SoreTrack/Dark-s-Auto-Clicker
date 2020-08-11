#include "app.h"
App::App() {};
App::~App() {};

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

		TTF_Init();
		if (TTF_Init())
		{
			std::cout << "Font Successfully Initialised! ...\n";
		}

		isRunning = true;
	} else {
		isRunning = false;
	}
}

void App::handleEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = event.motion.x;
			int y = event.motion.y;
			
			if ((x > bClick.x) && (x < bClick.x + bClick.w) && (y > bClick.y) && (y < bClick.y + bClick.h)) // Button Auto Click
			{
				std::cout << "Button clicked !\n";
			}
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_f)
			{
				keyF++;
				keyF++;
				if (keyF == 10)
				{
					std::cout << "\nYou said f*ck you to the program.\n";
					std::cout << "The program is angry.\n";
					std::cout << "The program will closed because you said f*ck you to it.\n";
					Sleep(2000);
					isRunning = false;
				}
			}

			if (keyF > 0) {
				keyF--;
			}
		}
	}
}

void App::GUI()
{
	// Rectangle
	bClick.x = 275;
	bClick.y = 200;
	bClick.w = 150;
	bClick.h = 50;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &bClick);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Text
	font = TTF_OpenFont("arial.ttf", 20);
	color = { 255, 255, 255 };
	surface = TTF_RenderText_Solid(font, "Auto Click", color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	tClick.x = 305;
	tClick.y = 211;

	SDL_QueryTexture(texture, NULL, NULL, &tClick.w, &tClick.h);

	SDL_RenderCopy(renderer, texture, NULL, &tClick);
}

void App::render()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_Quit();
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