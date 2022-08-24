#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"

namespace cool
{
	class CollisionComponent : public Component, public ICollision
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionEXit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData data;

	};
}