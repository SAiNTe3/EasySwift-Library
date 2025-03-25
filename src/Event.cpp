#include"../include/Event.hpp"

Event::~Event()
{

}

void Event::processEvent()
{
	glfwPollEvents();
}
bool Event::isKeyPressed(int key)
{
	return m_Keyboard.getKeyState(key) == Keyboard::KeyState::PRESS;
}
bool Event::isKeyReleased(int key)
{
	return m_Keyboard.getKeyState(key) == Keyboard::KeyState::RELEASE;
}
bool Event::isMousePressed(int button)
{
	return m_Mouse.getMouseState(button) == Mouse::MouseState::PRESS;
}
bool Event::isMouseReleased(int button)
{
	return m_Mouse.getMouseState(button) == Mouse::MouseState::RELEASE;
}
Keyboard::KeyState Event::getKeyState(int key)
{
	return m_Keyboard.getKeyState(key);
}
Mouse::MouseState Event::getMouseState(int button)
{
	return m_Mouse.getMouseState(button);
}

Mouse& Event::getMouse()
{
	return m_Mouse;
}

Keyboard& Event::getKeyboard()
{
	return m_Keyboard;
}
