#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace cool
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update()
	{
		//update tranfrom with input

		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::State::Held)
		{
			direction = Vector2::left;
		}

		if (g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			direction = Vector2::right;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			//thrust force
			//Vector2 force = Vector2::Rotate({ 1, 0 },math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->AppliedForce(direction * speed);

			//grav froce
			//force = (Vector2{ 400,300 } - m_owner->m_transform.position).Normalized() * 100.0f;
			//component->AppliedForce(force);
		}

		//jump
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			
			if (component)
			{
				component->AppliedForce(Vector2::up * 500);
			}
		}

	}

		bool PlayerComponent::Write(const rapidjson::Value & value) const
		{
			return true;
		}

		bool PlayerComponent::Read(const rapidjson::Value & value)
		{
			READ_DATA(value, speed);

			return true;
		}

		void PlayerComponent::OnCollisionEnter(Actor* other)
		{
			if (other->GetName() == "Coin")
			{
				Event event;
				event.name = "EVENT_ADD_POINTS";
				event.data = 100;

				g_eventManager.Notify(event);

				other->SetDestory();
			}

			//std::cout << " AHHHHHHHHHHHHHH";
		}

		void PlayerComponent::OnCollisionExit(Actor* other)
		{
			//std::cout << "AHHHHHHHHHOOOOOOOOOOOOOOO";
		}

}
