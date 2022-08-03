#include "../Engine/Engine.h"


using namespace std;

int main()
{
	cool::InitializeMemory();
	cool::SetFilePath("../Assets");

	//initialize engine

	cool::g_renderer.Initialize();
	cool::g_inputSystem.Initialize();
	cool::g_audioSystem.Initialize();

	//creates window
	cool::g_renderer.CreateWindow("Neumont", 800, 600);
	cool::g_renderer.setClearColor(cool::Color{ 60,60,60,255 });

	std::shared_ptr<cool::Texture> texture = std::make_shared<cool::Texture>();
	texture->Create(cool::g_renderer, "Kirby.png");
	{
		//game creation
		

		bool quit = false;
		while (!quit)
		{
			//update (engine)
			cool::g_time.Tick();
			cool::g_inputSystem.Update();
			cool::g_audioSystem.Update();

			if (cool::g_inputSystem.GetKeyDown(cool::key_escape)) quit = true;

			//renderer
			cool::g_renderer.BeginFrame();

			cool::g_renderer.Draw(texture, { 100,100 }, 0);

			cool::g_renderer.EndFrame();
		}
	}


	cool::g_audioSystem.Shutdown();
	cool::g_renderer.Shutdown();
}