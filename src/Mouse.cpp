#include "../include/Mouse.hpp"

Mouse::MouseState Mouse::getMouseState(int button)
{
    auto it = currentFrameState.find(button);
    return (it != currentFrameState.end()) ? it->second : RELEASE;
}
void Mouse::setMouseState(int key, MouseState state)
{
    currentFrameState[key] = state;
}