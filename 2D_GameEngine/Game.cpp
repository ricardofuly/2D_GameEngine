#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playerTexture;
SDL_FRect srcRect, destRect;

Game::Game()
{

};

Game::~Game()
{

};

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, width, height, flags);
		if (window == nullptr)
		{
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}
		else { std::cout << "Window Created!" << std::endl; }

		renderer = SDL_CreateRenderer(window, NULL);
		if (renderer == nullptr)
		{
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
		else 
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
	}
	
	playerTexture = TextureManager::LoadTexture("Textures/npc_elf.png", renderer);
};

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_EVENT_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
};

void Game::update()
{
	cnt++;

	destRect.h = 16;
	destRect.w = 16;
	destRect.x = cnt;

	std::cout << cnt << std::endl;
};

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, playerTexture, NULL, &destRect);
	SDL_RenderPresent(renderer);
};

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned!" << std::endl;
}