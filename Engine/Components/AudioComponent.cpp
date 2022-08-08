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

}
