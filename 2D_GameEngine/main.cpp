#include "Game.h"
#include "iostream"

Game* game = nullptr;

int main(int argc, const char *argv[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("Fuly Engine", 800, 600, false);

	while (game->running())
	{
        frameStart = static_cast<Uint32>(SDL_GetTicks());

		game->handleEvents();
		game->update();
		game->render();

        frameTime = static_cast<int>(SDL_GetTicks() - frameStart);
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	};

	game->clean();

	return 0;
}