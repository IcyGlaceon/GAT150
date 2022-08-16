#include "Engine.h"

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

	//load assets
	//std::shared_ptr<cool::Texture> texture = std::make_shared<cool::Texture>();
	//texture->Create(cool::g_renderer, "spaceShips_004.png");
	auto texture = cool::g_resources.Get<cool::Texture>("spaceShips_004.png", cool::g_renderer);

	auto font = cool::g_resources.Get<cool::Font>("sweetly Broken.ttf", cool::g_renderer);

	//std::shared_ptr<cool::Model> model = std::make_shared<cool::Model>();
	//model->Create("player.txt");

	auto model = cool::g_resources.Get<cool::Model>("player.txt", cool::g_renderer);
	//std::shared_ptr<cool::Model> model2 = cool::g_resources.Get<cool::Model>("player.txt");

	cool::g_audioSystem.AddAudio("laser", "Laser.wav");

	//create actors
	cool::Scene scene;
	

	cool::Transform transform{ {100,100}, 0, {1,1} };


	std::unique_ptr<cool::Actor> actor = cool::Factory::Instance().Create<cool::Actor>("Actor");
	actor->m_transform = transform;
	std::unique_ptr<cool::Component> pComponent = cool::Factory::Instance().Create<cool::Component>("PlayerComponent");
	actor->AddComponent(std::move(pComponent));
	
	/*/
	std::unique_ptr<cool::SpriteComponent> sComponent = std::make_unique<cool::SpriteComponent>();
	sComponent->m_texture = texture;
	actor->AddComponent(std::move(sComponent));
	*/

	std::unique_ptr<cool::ModelComponent> mComponent = std::make_unique<cool::ModelComponent>();
	mComponent->m_model = cool::g_resources.Get<cool::Model>("player.txt");
	actor->AddComponent(std::move(mComponent));
	

	std::unique_ptr<cool::AudioComponent> aComponent = std::make_unique<cool::AudioComponent>();
	aComponent->m_sound = "laser";
	actor->AddComponent(std::move(aComponent));
	

	std::unique_ptr<cool::Component> phComponent = cool::Factory::Instance().Create<cool::Component>("PhysicsComponent");
	actor->AddComponent(std::move(phComponent));


	cool::Transform transformC{ {40,40}, 0, {1,1} };
	std::unique_ptr<cool::Actor> child = std::make_unique <cool::Actor>(transformC);

	std::unique_ptr<cool::ModelComponent> mComponentC = std::make_unique<cool::ModelComponent>();
	mComponentC->m_model = cool::g_resources.Get<cool::Model>("player.txt");
	child->AddComponent(std::move(mComponentC));

	actor->AddChild(std::move(child));

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
		angle += 360.0f * cool::g_time.deltaTime;

		scene.Update();

		//renderer
		cool::g_renderer.BeginFrame();

		scene.Draw(cool::g_renderer);

		//cool::g_renderer.Draw(texture, { 400,400 }, angle, {0.5f,0.5f}, { 0.5f,1.0f });

		cool::g_renderer.EndFrame();
	}
	


	cool::g_audioSystem.Shutdown();
	cool::g_renderer.Shutdown();
}