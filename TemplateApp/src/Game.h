#pragma once

#include "Core/Application.h"

namespace App {

	class Game : public Application
	{
	public:
		Game(const AppSpecs& specs);
		~Game() override;

		void OnUpdate(float ts) override;
		void OnRender() override;
		void OnEvent(SDL_Event& event) override;
	private:
		SDL_Texture* m_Texture;
	};

}
