#pragma once
#include <iostream>
#include <Windows.h>
#include <SDL.h>

class App {
public:
	App();
	~App();

	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvent();
	void update();
	void render();
	void clean();

	void clicker();

	bool running();

private:
	bool autoClick = false;

	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};