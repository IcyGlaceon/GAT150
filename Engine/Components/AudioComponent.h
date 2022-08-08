#pragma once
#include "Framework/Component.h"

namespace cool
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;

		void Play();

		void Stop();

		std::string m_sound;
		bool m_playonAwake = false;
		float m_volume = 1;
		float m_pitch = 1;
		bool loop = false;

		

	};
}