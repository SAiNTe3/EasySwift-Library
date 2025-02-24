#include "include/Window.hpp"

int main()
{
    Window::Initialize(4, 6);
    Window window(800, 600, "Demo Window");
    while (window.isOpen())
    {
        window.clear();
        window.display();
    }
    Window::Terminate();
}