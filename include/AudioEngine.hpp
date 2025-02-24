#pragma once
#include "miniAudio/miniaudio.h"
#include <iostream>

class AudioEngine {
	ma_engine m_Engine;
public:
	AudioEngine();
	~AudioEngine();
	friend class Audio;
};