#include "ModelComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

namespace cool
{
	void ModelComponent::Update()
	{

	}

	void ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->m_transform);
	}

}
