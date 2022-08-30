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
		Scene(const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)

		void Update() override;
		void Initialize() override;
		void Draw(Renderer& renderer);
		
		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		template<typename T>
		T* GetActor();

		template<typename T = Actor>
		T* GetActorFromName(const std::string& name);

		template<typename T = Actor>
		std::vector<T*> GetActorFromTag(const std::string& tag);

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

	template<typename T>
	inline T* Scene::GetActorFromName(const std::string& name)
	{
		for (auto actor : m_actors)
		{
			if (name == Actor::GetName())
			{
				return dynamic_cast<T*>(std::get(*Actor));
			}
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Scene::GetActorFromTag(const std::string& tag)
	{
		std::vector<T*> result;

		for (auto actor : m_actors)
		{
			if (tag == Actor::GetTag())
			{
				T* tagActor = dynamic_cast<T*>(std::get(*Actor));
				if (tagActor) result.push_back(tagActor);
			}
		}

		return result;
	}
}