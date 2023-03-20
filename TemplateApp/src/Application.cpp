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
			m_IsRunning = false;
		}

		m_Window = SDL_CreateWindow(m_Specs.Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Specs.Width, m_Specs.Height, SDL_WINDOW_OPENGL);

		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
		// TODO: Do other render init stuff
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
					Exit();

				s_Game->OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			s_Game->OnUpdate(timeStep);

			// TODO: Setup render
			s_Game->OnRender();
			// TODO: End render

			SDL_Delay(16.6f);
		}
	}

	void Application::Exit()
	{
		m_IsRunning = false;
	}

}