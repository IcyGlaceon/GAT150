#pragma once
#include "RenderComponent.h"
#include "Renderer/Model.h"

namespace cool
{
	class Model;

	class ModelComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Model> m_model;
	};
}