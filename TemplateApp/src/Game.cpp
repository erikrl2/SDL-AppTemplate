#include "Game.h"

namespace App {

	Game::Game(const AppSpecs& specs)
		: Application(specs)
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
		m_Music = Mix_LoadMUS("assets/mp3.mp3");
		Mix_VolumeMusic(2);
		Mix_PlayMusic(m_Music, -1);
	}

	Game::~Game()
	{
		Mix_FreeMusic(m_Music);
		Mix_CloseAudio();
	}

	void Game::OnUpdate(float ts)
	{
	}

	void Game::OnEvent(SDL_Event& event)
	{
	}

	Application* CreateApplication()
	{
		return new Game({});
	}

}
