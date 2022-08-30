#pragma once
#include "Framework/Component.h"
#include "Serialization/Serializable.h"
#include "Audio/AudioChannel.h"

namespace cool
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		void Initialize() override;
		void Update() override;
		
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		AudioChannel m_channel;

		std::string m_sound;
		bool m_playonAwake = false;
		float m_volume = 1;
		float m_pitch = 1;
		bool loop = false;
	};
}