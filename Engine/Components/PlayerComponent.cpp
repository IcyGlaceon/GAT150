#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace cool
{
	void PlayerComponent::Update()
	{
		//update tranfrom with input

		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		}

		if (g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
		}

		float thrust = 0;
		if (g_inputSystem.GetKeyState(key_up) == InputSystem::State::Held)
		{
			thrust = 100;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			//thrust force
			Vector2 force = Vector2::Rotate({ 1, 0 },math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->AppliedForce(force);

			//grav froce
			force = (Vector2{ 400,300 } - m_owner->m_transform.position).Normalized() * 100.0f;
			component->AppliedForce(force);
		}

		m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
			}
		}
	}

}
