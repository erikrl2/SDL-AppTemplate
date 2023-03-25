#include "Game.h"

#include <SDL_ttf.h>

namespace App {

	Game::Game(const AppSpecs& specs)
		: Application(specs)
	{
		TTF_Init();

		TTF_Font* font = TTF_OpenFont("assets/OpenSans-Regular.ttf", 24);
		SDL_Surface* surface = TTF_RenderUTF8_Blended(font, "Hello World", { 255, 255, 255, 255 });

		m_Rect = { 50, 50, surface->w, surface->h };
		m_Text = SDL_CreateTextureFromSurface(m_Renderer, surface);

		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
	}

	Game::~Game()
	{
		SDL_DestroyTexture(m_Text);
	}

	void Game::OnUpdate(float ts)
	{
	}

	void Game::OnRender()
	{
		SDL_RenderCopy(m_Renderer, m_Text, NULL, &m_Rect);
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({});
	}

}
