#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objectTexture = TextureManager::LoadTexture(textureSheet, ren);

	xPos = x;
	yPos = y;
};

void GameObject::Update() 
{
   xPos++;
   yPos++;

   srcRect.h = 16;
   srcRect.w = 16;
   srcRect.x = 0;
   srcRect.y = 0;

   destRect.x = static_cast<float>(xPos); 
   destRect.y = static_cast<float>(yPos); 
   destRect.h = srcRect.h * 2.0f; 
   destRect.w = srcRect.w * 2.0f; 
}

void GameObject::Render() 
{
	SDL_RenderTexture(renderer, objectTexture, &srcRect, &destRect);
}