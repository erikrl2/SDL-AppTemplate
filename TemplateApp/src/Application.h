#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

int main();

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

		SDL_Window* GetWindow() const { return m_Window; }
		SDL_Renderer* GetRenderer() const { return m_Renderer; }
		void Exit();

		static Application& Get() { return *s_Game; }

		virtual void OnUpdate(float ts) = 0;
		virtual void OnRender() = 0;
		virtual void OnEvent(SDL_Event& event) = 0;
	private:
		void Run();
	private:
		AppSpecification m_Specs;
		bool m_IsRunning = true;
	protected:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
	private:
		inline static Application* s_Game;
		friend int ::main();
	};

	App::Application* CreateApplication();

}

