#include "include/Window.hpp"

int main()
{
	Window::Initialize(4, 6);
	Window window(800, 450, "DemoWindow", true, true);
	while (window.isOpen())
	{
		Event e;
		window.pollEvents(e);
		window.clear();
		window.display();
	}
	Window::Terminate();
}