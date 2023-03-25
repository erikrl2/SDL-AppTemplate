#include <iostream>

#include <SDL.h>

int main(int argc, char* argv[]);

namespace App {

	struct AppSpecs
	{
		std::string Name = "App";
		uint32_t Width = 640;
		uint32_t Height = 480;
	};

	class Application
	{
	public:
		Application(const AppSpecs& specs);
		virtual ~Application();

		virtual void OnUpdate(float ts) = 0;
		virtual void OnRender() = 0;
		virtual void OnEvent(SDL_Event& event) = 0;
	private:
		void Run();
	protected:
		bool m_IsRunning = true;
		SDL_Window* m_Window;
		SDL_GLContext m_Context;
	private:
		friend int ::main(int argc, char* argv[]);
	};

	Application* CreateApplication();

}

