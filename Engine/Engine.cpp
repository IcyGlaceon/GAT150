#include "Engine.h"

namespace cool
{
	InputSystem g_inputSystem;
	Time g_time;
	Renderer g_renderer;
	AudioSystem g_audioSystem;
	ResourceManager g_resources;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
	}
}