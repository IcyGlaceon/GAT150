#pragma once
#include "Serialization/Serializable.h"
#include "Math/Transform.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)

namespace cool
{
	class GameObject
	{
	public:
		GameObject() = default;
		
		virtual void Update() = 0;
	};
}