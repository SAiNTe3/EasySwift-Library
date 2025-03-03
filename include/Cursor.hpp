#pragma once
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../include/stbImage/stb_image.h"
class Cursor
{
	GLFWcursor* m_Cursor = nullptr;
	GLFWwindow* m_Window = nullptr;
public:
	enum Style
	{
		Arrow = GLFW_ARROW_CURSOR,
		IBeam = GLFW_IBEAM_CURSOR,
		Crosshair = GLFW_CROSSHAIR_CURSOR,
		Hand = GLFW_HAND_CURSOR,
		HResize = GLFW_HRESIZE_CURSOR,
		VResize = GLFW_VRESIZE_CURSOR
	};
	enum State
	{
		Normal = GLFW_CURSOR_NORMAL,
		Hidden = GLFW_CURSOR_HIDDEN,
		Disabled = GLFW_CURSOR_DISABLED
	};
public:
	Cursor();
	Cursor(Style style, GLFWwindow* window);
	~Cursor();
	void loadFromFile(const char* iconPath);
	void bind(GLFWwindow* window);
	void setStyle(Style style);
	void setState(State state);
	void reset();
};