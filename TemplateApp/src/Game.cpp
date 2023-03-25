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
		GPU_RectangleFilled2(m_Screen, { 100, 100, 100, 100 }, { 0, 255, 0, 255 });
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({});
	}

}
