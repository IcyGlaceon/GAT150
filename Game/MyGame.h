#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class MyGame : public cool::Game
{
public:
	enum class gameState
	{
		titleSceen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(cool::Renderer& renderer) override;

	void OnAddPoints(const cool::Event& event);
	void OnPlayerDead(const cool::Event& event);

private:
	gameState m_gameState = gameState::titleSceen;
	float m_stateTimer = 0;
	int m_lives = 3;
};