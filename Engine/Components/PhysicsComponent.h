#pragma once
#include "Framework/Component.h"
#include "Serialization/Serializable.h"

namespace cool
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;
		void AppliedForce(const Vector2& force) { acceleration += force; }


		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 velocity;
		Vector2 acceleration;

		float damping = 1;
	};
}