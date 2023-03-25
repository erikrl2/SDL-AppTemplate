#include <iostream>

#include <SDL_gpu.h>

int main(int argc, char* argv[]);

namespace App {

	struct AppSpecs
	{
		std::string Title = "App";
		int Width = 640;
		int Height = 480;
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
		GPU_Target* m_Screen;
	private:
		friend int ::main(int argc, char* argv[]);
	};

	App::Application* CreateApplication();

}

