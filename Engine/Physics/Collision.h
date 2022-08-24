#pragma once

namespace cool
{
	class Actor;

	class ICollision
	{
	public:
		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionEXit(Actor* other) = 0;
	};
}