#pragma once
#include <iostream>
#include "Mouse.hpp"
#include "Keyboard.hpp"

class Event
{
	Mouse m_Mouse;
	Keyboard m_Keyboard;
	friend class Window;
public:
	Event() = default;
	~Event();

	bool isKeyPressed(int key);
	bool isKeyReleased(int key);
	bool isMousePressed(int button);
	bool isMouseReleased(int button);
	Keyboard::KeyState getKeyState(int key);
	Mouse::MouseState getMouseState(int button);
protected:
	Mouse& getMouse();
	Keyboard& getKeyboard();
	void processEvent();
};