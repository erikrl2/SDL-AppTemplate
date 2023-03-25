#include "Application.h"

namespace App {

	Application::Application(const AppSpecs& specs)
	{
		if (SDL_Init(SDL_INIT_VIDEO))
		{
			std::cout << SDL_GetError() << std::endl;
			exit(1);
		}

		m_Window = SDL_CreateWindow(specs.Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, specs.Width, specs.Height, SDL_WINDOW_OPENGL);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

		SDL_RenderSetVSync(m_Renderer, 1);
	}

	Application::~Application()
	{
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
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
				if (event.type == SDL_QUIT)
					m_Running = false;

				OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			OnUpdate(timeStep);

			SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(m_Renderer);

			OnRender();

			SDL_RenderPresent(m_Renderer);
		}
	}

}