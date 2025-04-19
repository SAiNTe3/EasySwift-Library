#pragma once
#include "miniAudio/miniaudio.h"
#include <iostream>

class AudioEngine {
	ma_engine m_Engine;
public:
	AudioEngine();
	AudioEngine(ma_uint64 sampleRate);
	~AudioEngine();
	ma_uint64 getEngineSampleRate();
	friend class Audio;
};