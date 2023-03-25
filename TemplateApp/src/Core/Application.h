#include <iostream>

#include <SDL.h>

int main(int argc, char* argv[]);

namespace App {

	struct AppSpecs
	{
		std::string Name = "App";
		int Width = 640;
		int Height = 480;
	};

	class Application
	{
	public:
		Application(const AppSpecs& specs);
		virtual ~Application();

		virtual void OnUpdate(float ts) = 0;
		virtual void OnEvent(SDL_Event& event) = 0;
	private:
		void Run();
	protected:
		bool m_Running = true;
	private:
		friend int ::main(int argc, char* argv[]);
	};

	App::Application* CreateApplication();

}

