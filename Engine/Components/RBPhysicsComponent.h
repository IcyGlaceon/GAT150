#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace cool
{
	class RBPhysicsComponent : public PhysicsComponent
	{
	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		CLASS_DECLARATION(RBPhysicsComponent)

		void Initialize() override;
		void Update() override;
		void AppliedForce(const Vector2& force);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;

	};
}