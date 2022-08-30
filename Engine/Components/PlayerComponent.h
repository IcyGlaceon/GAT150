#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"

namespace cool
{
	class PlayerComponent : public Component, public ICollision
	{
	public:
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;
		
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		CLASS_DECLARATION(PlayerComponent)

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	
	public:
		float speed = 0;
	};
}