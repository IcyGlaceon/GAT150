#pragma once
#include "Math/Transform.h"

namespace cool
{
	class GameObject
	{
	public:
		GameObject() = default;
		
		virtual void Update() = 0;		
	};
}