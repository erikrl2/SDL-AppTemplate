#include "Game.h"

namespace App {

	Game::Game(const AppSpecs& specs)
		: Application(specs)
	{
	}

	Game::~Game()
	{
	}

	void Game::OnUpdate(float ts)
	{
	}

	void Game::OnRender()
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);

		SDL_Rect rect{ 100, 100, 100, 100 };
		SDL_RenderFillRect(m_Renderer, &rect);
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({});
	}

}
