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
#include <chrono>
#include <thread>
typedef unsigned int uint;

class Window
{
    GLFWwindow *m_Window = nullptr;
    float r = 0;
    float g = 0;
    float b = 0;
    float a = 1;
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
    void setBackgroundColor(float r, float g, float b, float a);
    void setBackgroundColor(int r, int g, int b, int a);
    void setWindowSize(int width, int height);
    void getWindowSize(int &width, int &height);
    glm::vec2 getWindowSize();
	glm::dvec2 getCursorPosition();
    void setWindowPosition(int x, int y);
    void getWindowPosition(int &x, int &y);
    glm::vec2 getWindowPosition();
    void closeWindow();
    void setWindowTitle(const char *title);
    HWND getWindowHandle();
    void move(int ax, int ay);
    void setVSync(bool value);
    void setFramerateLimit(double framerate);
    void draw(Sprite &sprite);
    //Update v1.1.2
	//Set cursor's properties
	void setCursorStyle(Cursor::Style style);
	void setCursorIcon(const char* iconPath);
	void setCursorState(Cursor::State state);
    void setWindowIcon(const char* iconPath);
};