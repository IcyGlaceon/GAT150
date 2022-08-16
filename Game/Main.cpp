#include "Engine.h"
#include <iostream>

int main()
{
	cool::InitializeMemory();
	cool::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = cool::json::Load("json.txt", document);
	

	std::string str;
	cool::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	cool::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	cool::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	cool::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	cool::json::Get(document, "float", f);
	std::cout << f << std::endl;

	cool::Vector2 v2;
	cool::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	cool::Color color;
	cool::json::Get(document, "color", color);
	std::cout << color << std::endl;

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