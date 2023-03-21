#include "Application.h"

namespace App {

	Application::Application(const AppSpecification& specs)
		: m_Specs(specs)
	{
		SDL_assert(!s_Game);
		s_Game = this;

		if (SDL_Init(SDL_INIT_VIDEO))
		{
			std::cout << SDL_GetError() << std::endl;
			exit(1);
		}

		int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
		m_Window = SDL_CreateWindow(m_Specs.Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Specs.Width, m_Specs.Height, flags);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	}

	Application::~Application()
	{
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	void Application::Run()
	{
		uint64_t lastTime = SDL_GetTicks64();

		while (m_IsRunning)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					m_IsRunning = false;

				s_Game->OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			s_Game->OnUpdate(timeStep);

			SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(m_Renderer);

			s_Game->OnRender();

			SDL_RenderPresent(m_Renderer);

			SDL_Delay(14);
		}
	}

	void Application::Exit()
	{
		m_IsRunning = false;
	}

}