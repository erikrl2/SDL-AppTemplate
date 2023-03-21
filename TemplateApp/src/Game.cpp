#include "Game.h"

namespace App {

	Game::Game(const AppSpecification& specs)
		: Application(specs)
	{
		m_Rect.x = 100;
		m_Rect.y = 100;
		m_Rect.w = 100;
		m_Rect.h = 100;
	}

	Game::~Game()
	{
	}

	void Game::OnUpdate(float ts)
	{
	}

	void Game::OnRender()
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRect(m_Renderer, &m_Rect);
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({ "Test" });
	}

}
