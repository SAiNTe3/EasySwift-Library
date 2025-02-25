#pragma once
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <unordered_map>

#define MOUSE_BUTTON_1 0
#define MOUSE_BUTTON_2 1
#define MOUSE_BUTTON_3 2
#define MOUSE_BUTTON_4 3
#define MOUSE_BUTTON_5 4
#define MOUSE_BUTTON_6 5
#define MOUSE_BUTTON_7 6
#define MOUSE_BUTTON_8 7
#define MOUSE_BUTTON_LAST MOUSE_BUTTON_8
#define MOUSE_BUTTON_LEFT MOUSE_BUTTON_1
#define MOUSE_BUTTON_RIGHT MOUSE_BUTTON_2
#define MOUSE_BUTTON_MIDDLE MOUSE_BUTTON_3

struct Mouse
{
    enum MouseState
    {
        PRESS,
        RELEASE
    };
    std::unordered_map<int, MouseState> currentFrameState = { {MOUSE_BUTTON_1,RELEASE} };
    MouseState getMouseState(int key);
    void setMouseState(int key, MouseState state);
};

#define MousePressed Mouse::MouseState::PRESS
#define MouseReleased Mouse::MouseState::RELEASE