#include "AudioComponent.h"
#include "Engine.h"

namespace cool
{
	AudioComponent::~AudioComponent()
	{
		Stop();
	}
	void AudioComponent::Initialize()
	{
		if (m_playonAwake)
		{
			Play();
		}
	}

	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		Stop();
		m_channel = g_audioSystem.PlayAudio(m_sound,m_volume,m_pitch, loop);
	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, m_sound);
		READ_DATA(value, m_volume);
		READ_DATA(value, m_pitch);
		READ_DATA(value, loop);

		g_audioSystem.AddAudio(m_sound, m_sound);

		return true;
	}

}
