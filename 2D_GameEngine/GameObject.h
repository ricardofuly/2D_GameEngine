#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x , int y);
	~GameObject();

	void Update();
	void Render();

protected:
private:

	int xPos;
	int yPos;

	SDL_Texture* objectTexture;
	SDL_FRect srcRect, destRect;
	SDL_Renderer* renderer;
};