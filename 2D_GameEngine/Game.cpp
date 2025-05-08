#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TexturesLibrary.h"

GameObject* player;
GameObject* enemy;

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
	
	player = new GameObject(Entity::player, renderer, 0 ,0);
	enemy = new GameObject(Entity::enemy, renderer, 50, 0);
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
	player->Update();
	enemy->Update();
};

void Game::render()
{
	SDL_RenderClear(renderer);

	player->Render();
	enemy->Render();


	SDL_RenderPresent(renderer);
};

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned!" << std::endl;
}