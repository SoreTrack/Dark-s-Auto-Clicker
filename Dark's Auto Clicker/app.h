#pragma once
#include <iostream>
#include <sstream> 
#include <string>
#include <Windows.h>
#include <Winuser.h>
#include <SDL.h>
#include <SDL_ttf.h>

class App {
public:
	App() {};
	~App() {};

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
	SDL_Window* window;
	SDL_Renderer* renderer;

	TTF_Font* font;
	SDL_Color color;
	SDL_Surface* surface;
	SDL_Texture* texture;

	SDL_Rect bClick;              // Auto Click Button
	SDL_Rect bCPS;                // CPS Config

	SDL_Rect tClick;			  // Auto Click Text
	SDL_Rect tCPS;                // CPS Config
	SDL_Rect tDev;                // Credit

	SDL_Rect rDev;                // Credit
};