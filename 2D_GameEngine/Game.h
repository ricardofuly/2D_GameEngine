#pragma once
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "iostream"

class Game 
{
public:

	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

private:
	
	int cnt = 0;
	bool isRunning;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};