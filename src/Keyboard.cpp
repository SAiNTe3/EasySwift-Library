#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../include/Keyboard.hpp"

Keyboard::KeyState Keyboard::getKeyState(int key)
{
    auto it = currentFrameState.find(key);
    return (it != currentFrameState.end()) ? it->second : RELEASE;
}
void Keyboard::setKeyState(int key, KeyState state)
{
    currentFrameState[key] = state;
}