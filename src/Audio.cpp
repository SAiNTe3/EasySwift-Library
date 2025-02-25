#define MINIAUDIO_IMPLEMENTATION
#include "../include/Audio.hpp"

Audio::Audio() = default;
Audio::Audio(const std::string &audioPath, AudioEngine &engine)
{
	this->bindEngine(&engine);
	this->loadFromFile(audioPath);
}
Audio::~Audio()
{
	ma_sound_uninit(&m_Sound);
}
void Audio::play()
{
	if (!m_Engine)
	{
		return;
	}
	if (!m_Initialized)
	{
		return;
	}
	if (m_Paused)
	{
		ma_sound_seek_to_pcm_frame(&m_Sound, m_PausedCurser);
		m_Paused = false;
	}
	ma_sound_start(&m_Sound);
}
void Audio::pause()
{
	if (m_Paused)
	{
		return;
	}
	ma_sound_get_cursor_in_pcm_frames(&m_Sound, &m_PausedCurser);
	ma_sound_stop(&m_Sound);
	m_Paused = true;
}
void Audio::stop()
{
	ma_sound_stop(&m_Sound);
	m_PausedCurser = 0;
	m_Paused = false;
}
void Audio::loadFromFile(const std::string &path)
{
	m_Result = ma_sound_init_from_file(m_Engine, path.c_str(), 0, nullptr, nullptr, &m_Sound);
	if (m_Result != MA_SUCCESS)
	{
		return;
	}
	m_Initialized = true;
}
void Audio::setLoop(bool isLooping)
{
	ma_sound_set_looping(&m_Sound, isLooping);
}
void Audio::setVolume(float volume)
{
	ma_sound_set_volume(&m_Sound, volume);
}
float Audio::getVolume() const
{
	return ma_sound_get_volume(&m_Sound);
}
void Audio::setPan(float pan)
{
	ma_sound_set_pan(&m_Sound, pan);
}
float Audio::getPan() const
{
	return ma_sound_get_pan(&m_Sound);
}
void Audio::setPitch(float pitch)
{
	ma_sound_set_pitch(&m_Sound, pitch);
}
float Audio::getPitch() const
{
	return ma_sound_get_pitch(&m_Sound);
}
void Audio::bindEngine(AudioEngine *engine)
{
	m_Engine = &(engine->m_Engine);
}