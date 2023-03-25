#include "Application.h"

namespace App {

	Application::Application(const AppSpecs& specs)
	{
		m_Screen = GPU_Init(specs.Width, specs.Height, GPU_DEFAULT_INIT_FLAGS);
	}

	Application::~Application()
	{
		GPU_FreeTarget(m_Screen);
		GPU_Quit();
	}

	void Application::Run()
	{
		uint64_t lastTime = SDL_GetTicks64();

		while (m_Running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					m_Running = false;

				OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			OnUpdate(timeStep);

			GPU_Clear(m_Screen);

			OnRender();

			GPU_Flip(m_Screen);
		}
	}

}