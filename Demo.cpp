#include "include/Window.hpp"

int main()
{
	Window::Initialize(4, 6);
	Window window(800, 450, "DemoWindow", true, true);
	while (window.isOpen())
	{
		window.pollEvents();
		window.clear();
		window.display();
	}
	Window::Terminate();
}