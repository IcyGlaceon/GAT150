#include "MyGame.h"
#include "Engine.h"

void MyGame::Initialize()
{
	m_scene = std::make_unique<cool::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Scenes/level.txt", "Scenes/prefab.txt", "Scenes/Tilemap.txt"};

	for (auto sceneName : sceneNames)
	{
	bool success = cool::json::Load(sceneName, document);
	if (!success)
	{
		LOG("couldn't load scene %s", sceneName.c_str());
		continue;
	}

	m_scene->Read(document);
	}

	m_scene->Initialize();

	/*
	
	*/

	cool::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnAddPoints, this, std::placeholders::_1));
}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)
	{
	case gameState::titleSceen:
		if (cool::g_inputSystem.GetKeyState(cool::key_space) == cool::InputSystem::State::Pressed)
		{
			//m_scene->GetActorFromName("Title")->SetActive(false);
			m_gameState = gameState::startLevel;
		}
		break;

	case gameState::startLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = cool::Factory::Instance().Create<cool::Actor>("Coin");
			actor->m_transform.position = { cool::randomf(0,800),100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;

	case gameState::game:
		break;

	case gameState::playerDead:
		m_stateTimer -= cool::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives < 0) ? gameState::startLevel : gameState::gameOver;
		}

		break;
	
	case gameState::gameOver:
		break;
	
	default:
		break;
	}

	m_scene->Update();
}

void MyGame::Draw(cool::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnAddPoints(const cool::Event& event)
{
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void MyGame::OnPlayerDead(const cool::Event& event)
{
	m_gameState = gameState::playerDead;
	m_stateTimer = 20;
	m_lives--;
}
