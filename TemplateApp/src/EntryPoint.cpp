#include "Application.h"

int main()
{
	SDL_SetMainReady();

	auto app = App::CreateApplication();

	app->Run();

	delete app;
}
