#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	if (tempSurface == nullptr)
	{
		std::cerr << "IMG_Load Error: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_DestroySurface(tempSurface);
	if (texture == nullptr)
	{
		std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}