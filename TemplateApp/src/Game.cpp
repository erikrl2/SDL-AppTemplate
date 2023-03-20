#include "Game.h"

namespace App {

	Game::Game(const AppSpecification& specs)
		: Application(specs)
	{
	}

	Game::~Game()
	{
	}

	void Game::OnUpdate(float ts)
	{
		printf("%f\n", ts);
	}

	void Game::OnRender()
	{
	}

	void Game::OnEvent(SDL_Event& event)
	{
		switch (event.type)
		{
		}
	}

	Application* CreateApplication()
	{
		return new Game({"Test"});
	}

}
