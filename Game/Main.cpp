#include "Engine.h"


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
	

	//create actors
	cool::Scene scene;
	

	cool::Transform transform{ {100,100}, 180, {1,1} };

	std::unique_ptr<cool::Actor> actor = std::make_unique <cool::Actor>(transform);
	std::unique_ptr<cool::PlayerComponent> pComponent = std::make_unique<cool::PlayerComponent>();
	actor->AddComponent(std::move(pComponent));
	std::unique_ptr<cool::SpriteComponent> sComponent = std::make_unique<cool::SpriteComponent>();
	sComponent->m_texture = texture;
	actor->AddComponent(std::move(sComponent));

	scene.Add(std::move(actor));

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

		//update scene
		angle += 180.0f * cool::g_time.deltaTime;
		scene.Update();

		//renderer
		cool::g_renderer.BeginFrame();

		scene.Draw(cool::g_renderer);

		cool::g_renderer.Draw(texture, { 400,400 }, angle, {0.5f,0.5f}, { 0.5f,1.0f });

		cool::g_renderer.EndFrame();
	}
	


	cool::g_audioSystem.Shutdown();
	cool::g_renderer.Shutdown();
}