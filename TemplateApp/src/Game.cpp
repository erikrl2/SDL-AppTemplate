#include "Game.h"

#include <SDL_image.h>

namespace App {

	Game::Game(const AppSpecification& specs)
		: Application(specs)
	{
		m_Texture = IMG_LoadTexture(m_Renderer, "assets/test.png");

		SDL_Surface* img = IMG_Load("assets/test.png");
		IMG_SaveJPG(img, "assets/test-copy.jpg", 50);
	}

	Game::~Game()
	{
		SDL_DestroyTexture(m_Texture);
	}

	void Game::OnUpdate(float ts)
	{
	}

	void Game::OnRender()
	{
		SDL_RenderCopy(m_Renderer, m_Texture, NULL, NULL);
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({ "Test" });
	}

}
