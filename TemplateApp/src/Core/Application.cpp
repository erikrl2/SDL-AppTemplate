#include "Application.h"

#include <glad/glad.h>

namespace App {

	Application::Application(const AppSpecs& specs)
	{
		if (SDL_Init(SDL_INIT_VIDEO))
		{
			std::cout << SDL_GetError() << std::endl;
			exit(1);
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		m_Window = SDL_CreateWindow(specs.Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, specs.Width, specs.Height, SDL_WINDOW_OPENGL);

		m_Context = SDL_GL_CreateContext(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			std::cout << SDL_GetError() << std::endl;
			exit(1);
		}

		SDL_GL_SetSwapInterval(1);

		std::cout << glGetString(GL_VENDOR) << std::endl;
		std::cout << glGetString(GL_RENDERER) << std::endl;
		std::cout << glGetString(GL_VERSION) << std::endl;
	}

	Application::~Application()
	{
		SDL_GL_DeleteContext(m_Context);
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

				OnEvent(event);
			}

			uint64_t time = SDL_GetTicks64();
			float timeStep = (time - lastTime) / 1000.0f;
			lastTime = time;

			OnUpdate(timeStep);

			glClearColor(0.7f, 0.3f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			OnRender();

			SDL_GL_SwapWindow(m_Window);
		}
	}

}