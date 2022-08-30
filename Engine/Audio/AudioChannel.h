#pragma once

namespace FMOD
{
	class Channel;
}

namespace cool
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) : m_channel(channel) {}

		bool IsPlaying();
		void Stop();

		float GetPitch();
		void SetPitch(float pitch);

		float GetVolume();
		void SetVolume(float volume);


	private:
		FMOD::Channel* m_channel = nullptr;
	};
}