#pragma once
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"
#include "Sprite.hpp"
#include "Cursor.hpp"
#include "Event.hpp"
#include "Text.hpp"
#include <chrono>
#include <thread>
typedef unsigned int uint;

class Window
{
    GLFWwindow *m_Window = nullptr;
    glm::vec4 m_BackgroundColor;
    double m_Framerate = 0;
    bool m_Vsync = true;
    double m_LastFrameTime = 0;
    double m_TimePerFrame = 0;
    Event m_Event;
    Cursor m_Cursor;
    static void KeyEventCallback(GLFWwindow *window, int key, int scancode, int action, int modes);
    static void MouseEventCallback(GLFWwindow *window, int button, int action, int mods);


public:
    static void Initialize(int major, int minor);
    static void Terminate();
    Window(uint width, uint height, const char *title, bool visiable = true, bool resizeable = true);
    ~Window();
    bool isOpen();
    void display();
    void clear();
    void pollEvents(Event& e);
    void showWindow();
    void hideWindow();
    void setBackgroundColor(glm::vec4 rgba_float);
    void setBackgroundColor(glm::uvec4 rgba_int);
    void setWindowSize(glm::vec2 size);
    glm::ivec2 getWindowSize();
	glm::dvec2 getCursorPosition();
    void setWindowPosition(glm::vec2 pos);
    glm::vec2 getWindowPosition();
    void closeWindow();
    void setWindowTitle(const char *title);
    HWND getWindowHandle();
    void move(glm::vec2 offset);
    void setVSync(bool value);
    void setFramerateLimit(double framerate);
    void draw(Sprite &sprite);
    void draw(Text& text);
    //Update v1.1.2
	//Set cursor's properties
	void setCursorStyle(Cursor::Style style);
	void setCursorIcon(const char* iconPath);
	void setCursorState(Cursor::State state);
    void setWindowIcon(const char* iconPath);
};