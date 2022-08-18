#include "Engine.h"
#include <iostream>

int main()
{
	cool::InitializeMemory();
	cool::SetFilePath("../Assets");
	

	
	//initialize engine

	cool::g_renderer.Initialize();
	cool::g_inputSystem.Initialize();
	cool::g_audioSystem.Initialize();
	cool::g_resources.Initialize();

	cool::Engine::Instance().Register();

	//creates window
	cool::g_renderer.CreateWindow("Neumont", 800, 600);
	cool::g_renderer.setClearColor(cool::Color{ 60,60,60,255 });

	//create actors
	cool::Scene scene;
	
	rapidjson::Document document;
	bool success = cool::json::Load("level.txt", document);

	scene.Read(document);

	float angle = 0;

	//game creation
	bool quit = false;
	while (!quit)
	{
		//update (engine)
		cool::g_time.Tick();
		cool::g_inputSystem.Update();
		cool::g_audioSystem.Update();

		if (cool::g_inputSystem.GetKeyDown(cool::key_escape)) quit = true;

		scene.Update();

		//renderer
		cool::g_renderer.BeginFrame();

		scene.Draw(cool::g_renderer);

		cool::g_renderer.EndFrame();
	}
	


	cool::g_audioSystem.Shutdown();
	cool::g_renderer.Shutdown();
	
}