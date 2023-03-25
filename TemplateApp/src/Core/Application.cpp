#include "Application.h"

namespace App {

	Application::Application(const AppSpecs& specs)
	{
		SDL_Init(SDL_INIT_AUDIO);
	}

	Application::~Application()
	{
		SDL_Quit();
	}

	void Application::Run()
	{
		uint64_t lastTime = SDL_GetTicks64();

		while (m_Running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			OnUpdate(timeStep);
		}
	}

}