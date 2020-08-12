#pragma once
#include <iostream>
#include <sstream> 
#include <string>
#include <Windows.h>
#include <Winuser.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class App {
public:
	~App();

	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvent();
	void GUI();
	void render();
	void clean();

	void clicker();

	bool running();

private:
	int CPS = 20;
	int keyF = 0;

	bool pressed = false;
	bool autoClick = false;

	bool isRunning = true;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Color color{
		this->color.r = 255,
		this->color.g = 255,
		this->color.b = 255,
		this->color.a = 255
	};

	TTF_Font* font = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;

	SDL_Rect bClick { // Auto Click Button
		this->bClick.x = 275,
		this->bClick.y = 200,
		this->bClick.w = 150,
		this->bClick.h = 50
	};              
	SDL_Rect bCPS{                // CPS Config
		this->bCPS.x = 323,
		this->bCPS.y = 255,
		this->bCPS.w = 50,
		this->bCPS.h = 20
	};

	SDL_Rect tClick {						// Auto Click Text
		this->tClick.x = 305,
		this->tClick.y = 211
	};
	SDL_Rect tCPS {						    // CPS Config
		this->tCPS.x = 341,
		this->tCPS.y = 257,
	};
	SDL_Rect tDev;                          // Credit

	SDL_Rect rDev {                         // Credit
		this->rDev.x = 0,
		this->rDev.y = 390
	};
};