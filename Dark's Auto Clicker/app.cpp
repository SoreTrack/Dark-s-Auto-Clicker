#include "app.h"

App::~App() { }

void App::init(const char* title, int xpos, int ypos, int width, int height) // Error code 0
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialised! ...\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		if (window)
		{
			std::cout << "Window Successfully Created! ...\n";
		}
		else {
			MessageBox(
				0,
				(LPCWSTR)L"Window can not be created :(\nYou may contact me on discord : SoreTrack#1048",
				(LPCWSTR)L"SDL Error !  Error 0:2",
				MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
			);
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Successfully Created! ...\n";
		}
		else {
			MessageBox(
				0,
				(LPCWSTR)L"Renderer can not be created :(\nYou may contact me on discord : SoreTrack#1048",
				(LPCWSTR)L"SDL Error !  Error 0:3",
				MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
			);
		}

		TTF_Init();
		if (TTF_Init())
		{
			std::cout << "Font Successfully Initialised! ...\n";
		}

		this->isRunning = true;
	}
	else {
		MessageBox(
			0,
			(LPCWSTR)L"SDL2 can not be initialized :(\nYou may contact me on discord : SoreTrack#1048",
			(LPCWSTR)L"SDL Error ! Error 0:1",
			MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
		);
		this->isRunning = false;
	}
	std::cout << "\n--------------------------------------------------------------------------------\n";

	std::cout << "Copyright 2020, SoreTrack, All rights reserved.\n";

	std::cout << "\nThis is a closed ALPHA. Please, report all bugs and issues to SoreTrack.\n";
	std::cout << "An ALPHA mean that only mains features are added.\n";
	std::cout << "My Discord : SoreTrack#1048\n\n";

	std::cout << "--------------------------------------------------------------------------------\n";

	std::cout << "TIP : Press F5 to start the auto clicker !\n";
	std::cout << "TIP : Press ESCAPE or F7 to stop the auto clicker !\n";
	std::cout << "TIP : Hold F7 to kill the program !\n";
}

void App::handleEvent()
{
	int keyCode = 0;
	if (GetAsyncKeyState(VK_F5) != 0 && pressed == false) // F5 code 1
	{
		keyCode = 1;
		this->pressed = true;
		while (GetAsyncKeyState(VK_F5) & 0x8000) {} // Prevent to hold
		this->pressed = false;
	}

	if (GetAsyncKeyState(VK_F7) != 0 && pressed == false) // F7 code 2
	{
		keyCode = 2;
		this->pressed = true;
		int time = 0;
		while (GetAsyncKeyState(VK_F7) & 0x8000) {
			Sleep(1);
			time++;
			std::cout << time << std::endl;
			if (time >= 1000) {
				MessageBox(
					0,
					(LPCWSTR)L"User a sucessfuly grab the ShotGun\nThe program has been killed !",
					(LPCWSTR)L"Nice job ! You've killed the program !",
					MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
				);
				this->isRunning = false;
			}
		}
		this->pressed = false;
	}

	if (GetAsyncKeyState(VK_ESCAPE) != 0 && pressed == false) // ESCAPE code 3
	{
		keyCode = 3;
		this->pressed = true;
		while (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {} // Prevent to hold
		this->pressed = false;
	}

	SDL_Event event;
	while (SDL_PollEvent(&event) || keyCode > 0)
	{
		if (event.type == SDL_QUIT)
		{
			this->isRunning = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = event.motion.x;
			int y = event.motion.y;

			if ((x > bCPS.x) && (x < bCPS.x + bCPS.w) && (y > bCPS.y) && (y < bCPS.y + bCPS.h)) // CPS
			{
				std::cout << "Enter the number of CPS you want to have : ";
				std::cin >> CPS;
				std::cout << "CPS had been set to : " << CPS << std::endl;

				update = true;
			}

			if ((x > bClick.x) && (x < bClick.x + bClick.w) && (y > bClick.y) && (y < bClick.y + bClick.h) || keyCode == 1) // Button Auto Click
			{
				if (!autoClick)
				{
					Sleep(50);
					std::cout << "Start in 3 seconds !\n";
					Sleep(1000);
					std::cout << "Start in 2 seconds !\n";
					Sleep(1000);
					std::cout << "Start in 1 seconds !\n";
					Sleep(1000);
					std::cout << "Auto Clicker activated : " << CPS << " CPS !\n";

					this->autoClick = true;
				}
				else
				{
					std::cout << "Auto Clicker desactivated !\n";
					this->autoClick = false;
				}
			}
		}
		if (event.type == SDL_KEYDOWN || keyCode >= 2)
		{
			if (keyCode == 2 || keyCode == 3) // KeyCode F7 & KeyCode ESPCAPE
			{
				std::cout << "Auto Clicker desactivated !\n";
				this->autoClick = false;
			}
			if (event.key.keysym.sym == SDLK_f)
			{
				this->keyF++;
				this->keyF++;
				if (keyF == 10)
				{
					MessageBox(
						0,
						(LPCWSTR)L"You said f*ck you to the program.\nThe program is angry.\nThe program will closed because you said f*ck you to it.\n",
						(LPCWSTR)L"What did you do ?? The program look so mad !",
						MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
					);
					this->isRunning = false;
				}
			}

			if (keyF > 0) {
				this->keyF--;
			}
		}
		keyCode = 0;
	}
}

void App::GUI()
{
	const char* scCPS;
	std::string sCPS;
	std::stringstream sConvertCPS;
	sConvertCPS << this->CPS;
	sCPS = sConvertCPS.str();
	scCPS = (char*)sCPS.c_str();

	// Click Rectangle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &bClick);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Click Text
	font = TTF_OpenFont("arial.ttf", 20);
	this->surface = TTF_RenderText_Solid(font, "Auto Click", this->color);
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &tClick.w, &tClick.h);

	SDL_RenderCopy(renderer, texture, NULL, &tClick);

	// CPS Rectangle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &bCPS);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// CPS Text
	font = TTF_OpenFont("arial.ttf", 14);
	this->surface = TTF_RenderText_Solid(font, scCPS, this->color);
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &tCPS.w, &tCPS.h);

	SDL_RenderCopy(renderer, texture, NULL, &tCPS);

	// Credit
	font = TTF_OpenFont("arial.ttf", 10);
	this->surface = TTF_RenderText_Solid(font, "By SoreTrack", this->color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &rDev.w, &rDev.h);

	SDL_RenderCopy(renderer, texture, NULL, &rDev);

	sCPS.erase();
	sConvertCPS.clear();

	font = nullptr;
	scCPS = nullptr;
	delete font;
	delete scCPS;
}

void App::render()
{
	SDL_RenderPresent(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

void App::setUpdate(bool value)
{
	this->update = value;
}

bool App::getUpdate()
{
	if (this->update == true)
	{
		SDL_RenderClear(renderer);
	}
	return this->update;
}

bool App::running()
{
	return this->isRunning;
}

void App::clicker()
{
	int delay = 1000 / CPS;
	if (autoClick)
	{
		POINT cursorPos;
		GetCursorPos(&cursorPos);

		mouse_event(MOUSEEVENTF_LEFTDOWN, cursorPos.x, cursorPos.y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);
	}
}