#pragma once

#include "Core/Application.h"

namespace App {

	class Game : public Application
	{
	public:
		Game(const AppSpecification& specs);
		~Game() override;

		void OnUpdate(float ts) override;
		void OnRender() override;
		void OnEvent(SDL_Event& event) override;
	private:
		// Members
	};

}
