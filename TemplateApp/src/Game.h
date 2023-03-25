#pragma once

#include "Core/Application.h"

#include <SDL_mixer.h>

namespace App {

	class Game : public Application
	{
	public:
		Game(const AppSpecs& specs);
		~Game() override;

		void OnUpdate(float ts) override;
		void OnEvent(SDL_Event& event) override;
	private:
		Mix_Music* m_Music;
	};

}
