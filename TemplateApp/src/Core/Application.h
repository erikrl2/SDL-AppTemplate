#include <iostream>

#include <SDL.h>

int main(int argc, char* argv[]);

namespace App {

	struct AppSpecification
	{
		std::string Name = "App";
		uint32_t Width = 640;
		uint32_t Height = 480;
	};

	class Application
	{
	public:
		Application(const AppSpecification& specs);
		virtual ~Application();

		virtual void OnUpdate(float ts) = 0;
		virtual void OnRender() = 0;
		virtual void OnEvent(SDL_Event& event) = 0;

		void Exit() { m_IsRunning = false; }

		SDL_Window* GetWindow() const { return m_Window; }

		static Application& Get() { return *s_App; }
	private:
		void Run();
	private:
		AppSpecification m_Specs;
		bool m_IsRunning = true;
	protected:
		SDL_Window* m_Window;
		SDL_GLContext m_Context;
	private:
		inline static Application* s_App;
		friend int ::main(int argc, char* argv[]);
	};

	Application* CreateApplication();

}

