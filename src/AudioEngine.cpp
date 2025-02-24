#include "../include/AudioEngine.hpp"

AudioEngine::AudioEngine()
{
    ma_engine_init(nullptr, &m_Engine);
}
AudioEngine::~AudioEngine()
{
    ma_engine_uninit(&m_Engine);
}