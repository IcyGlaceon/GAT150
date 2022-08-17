#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

namespace cool
{
	void SpriteComponent::Update()
	{

	}

	void SpriteComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(m_texture, m_owner->m_transform);
	}

	bool SpriteComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteComponent::Read(const rapidjson::Value& value)
	{

		return true;
	}

}
