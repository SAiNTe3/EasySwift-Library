#pragma once
#include <iostream>
#include "Mouse.hpp"
#include "Keyboard.hpp"

class Event
{
	Mouse m_Mouse;
	Keyboard m_Keyboard;
public:
	Event() = default;
	~Event();
	/// <summary>
	/// Warning: Do not call this method proactively!
	/// </summary>
	void processEvent();
	bool isKeyPressed(int key);
	bool isKeyReleased(int key);
	bool isMousePressed(int button);
	bool isMouseReleased(int button);
	Keyboard::KeyState getKeyState(int key);
	Mouse::MouseState getMouseState(int button);
	Mouse& getMouse();
	Keyboard& getKeyboard();
};