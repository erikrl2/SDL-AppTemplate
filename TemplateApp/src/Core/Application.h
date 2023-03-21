#include <iostream>

#include <SDL.h>

int main(int argc, char* argv[]);

namespace App {

	struct AppSpecification
	{
		std::string Name = "App";
		int Width = 640;
		int Height = 480;
	};

	class Application
	{
	public:
		Application(const AppSpecification& specs);
		virtual ~Application();

		virtual void OnUpdate(float ts) = 0;
		virtual void OnRender() = 0;
		virtual void OnEvent(SDL_Event& event) = 0;

		SDL_Window* GetWindow() const { return m_Window; }
		SDL_Renderer* GetRenderer() const { return m_Renderer; }
		const AppSpecification& GetSpecs() const { return m_Specs; }
		void Exit();

		static Application& Get() { return *s_Game; }
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
		friend int ::main(int argc, char* argv[]);
	};

	App::Application* CreateApplication();

}

