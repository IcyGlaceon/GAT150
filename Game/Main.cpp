#include "Engine.h"
#include "MyGame.h"
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
	cool::g_physicsSystem.Initialize();
	cool::g_eventManager.Initialize();

	cool::Engine::Instance().Register();

	//creates window
	cool::g_renderer.CreateWindow("Neumont", 800, 600);
	cool::g_renderer.setClearColor(cool::Color{ 60,60,60,255 });

	//create game
	std::unique_ptr<MyGame> game = std::make_unique<MyGame>();
	game->Initialize();
	
	float angle = 0;

	//game creation
	bool quit = false;
	while (!quit)
	{
		//update (engine)
		cool::g_time.Tick();
		cool::g_inputSystem.Update();
		cool::g_audioSystem.Update();
		cool::g_physicsSystem.Update();
		cool::g_eventManager.Update();

		if (cool::g_inputSystem.GetKeyDown(cool::key_escape)) quit = true;

		game->Update();

		//renderer
		cool::g_renderer.BeginFrame();

		game->Draw(cool::g_renderer);

		cool::g_renderer.EndFrame();
	}
	game->Shutdown();
	game.reset();

	cool::Factory::Instance().Shutdown();

	cool::g_audioSystem.Shutdown();
	cool::g_renderer.Shutdown();
	cool::g_inputSystem.Shutdown();
	cool::g_eventManager.Shutdown();
	cool::g_physicsSystem.Shutdown();
	
}