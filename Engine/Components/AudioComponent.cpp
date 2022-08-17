#include "AudioComponent.h"
#include "Engine.h"

namespace cool
{
	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		cool::g_audioSystem.PlayAudio(m_sound, loop);
	}

	void AudioComponent::Stop()
	{
	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{

		return true;
	}

}
