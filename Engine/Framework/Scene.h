#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace cool
{

	//forward declaration
	class Actor;
	class Renderer;
	class Game;

	class Scene : public GameObject, public ISerializable
	{
	public:
		Scene() = default;
		Scene(Game* game) :m_game{ game } {}
		~Scene() = default;

		void Update() override;
		void Initialize() override;
		void Draw(Renderer& renderer);
		
		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		Game* GetGame() { return m_game; }

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
		Game* m_game;

	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		

		return nullptr;
	}
}