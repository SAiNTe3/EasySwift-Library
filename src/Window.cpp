#include "../include/Window.hpp"

Window::Window(uint width, uint height, const char* title, bool visiable, bool resizeable)
{
	glfwWindowHint(GLFW_VISIBLE, visiable);
	glfwWindowHint(GLFW_RESIZABLE, resizeable);
	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (m_Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	glViewport(0, 0, width, height);
	glfwSetWindowSizeCallback(
		m_Window,
		[](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		});
	glfwSetKeyCallback(m_Window, KeyEventCallback);
	glfwSetMouseButtonCallback(m_Window, MouseEventCallback);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m_Cursor.bind(m_Window);
	m_Cursor.setStyle(Cursor::Style::Arrow);
}
Window::~Window()
{
	glfwDestroyWindow(this->m_Window);
}
bool Window::isOpen()
{
	return !glfwWindowShouldClose(m_Window);
}
void Window::display()
{
	if (!m_Vsync)
	{
		double elapsed = glfwGetTime() - m_LastFrameTime;
		double sleepTime = m_TimePerFrame - elapsed;
		if (sleepTime > 0)
		{
			std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
		}
	}
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
	m_LastFrameTime = glfwGetTime();
}
void Window::clear()
{
	glfwMakeContextCurrent(m_Window);
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Window::pollEvents()
{
	glfwPollEvents();
}
glm::dvec2 Window::getCursorPosition()
{
	glm::dvec2 pos;
	glfwGetCursorPos(m_Window, &pos.x, &pos.y);
	return pos;
}
bool Window::isKeyPressed(int key)
{
	return m_Keyboard.getKeyState(key) == Keyboard::KeyState::PRESS;
}
bool Window::isKeyReleased(int key)
{
	return m_Keyboard.getKeyState(key) == Keyboard::KeyState::RELEASE;
}
bool Window::isMousePressed(int button)
{
	return m_Mouse.getMouseState(button) == Mouse::MouseState::PRESS;
}
bool Window::isMouseReleased(int button)
{
	return m_Mouse.getMouseState(button) == Mouse::MouseState::RELEASE;
}
Keyboard::KeyState Window::getKeyState(int key)
{
	return m_Keyboard.getKeyState(key);
}
Mouse::MouseState Window::getMouseState(int button)
{
	return m_Mouse.getMouseState(button);
}
void Window::showWindow()
{
	glfwShowWindow(this->m_Window);
}
void Window::hideWindow()
{
	glfwHideWindow(this->m_Window);
}
void Window::setBackgroundColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
void Window::setBackgroundColor(int r, int g, int b, int a)
{
	this->r = static_cast<float>(r) / 255;
	this->g = static_cast<float>(g) / 255;
	this->b = static_cast<float>(b) / 255;
	this->a = static_cast<float>(a) / 255;
}
void Window::setWindowSize(int width, int height)
{
	glfwSetWindowSize(this->m_Window, width, height);
}
void Window::getWindowSize(int& width, int& height)
{
	glfwGetWindowSize(this->m_Window, &width, &height);
}
glm::vec2 Window::getWindowSize()
{
	int width, height;
	getWindowSize(width, height);
	return glm::vec2(width, height);
}
void Window::setWindowPosition(int x, int y)
{
	glfwSetWindowPos(this->m_Window, x, y);
}
void Window::getWindowPosition(int& x, int& y)
{
	glfwGetWindowPos(this->m_Window, &x, &y);
}
glm::vec2 Window::getWindowPosition()
{
	int x, y;
	getWindowPosition(x, y);
	return glm::vec2(x, y);
}
void Window::closeWindow()
{
	glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
}
void Window::setWindowTitle(const char* title)
{
	glfwSetWindowTitle(m_Window, title);
}
HWND Window::getWindowHandle()
{
	return glfwGetWin32Window(m_Window);
}
void Window::move(int ax, int ay)
{
	int x, y;
	this->getWindowPosition(x, y);
	this->setWindowPosition(ax + x, ay + y);
}
void Window::setVSync(bool value)
{
	m_Vsync = value;
	glfwSwapInterval(value);
	if (value)
	{
		m_Framerate = 0;
		m_TimePerFrame = 0;
	}
}
void Window::setFramerateLimit(double framerate)
{
	if (framerate <= 0)
		return;
	if (m_Vsync)
	{
		return;
	}
	m_Framerate = framerate;
	m_TimePerFrame = 1.0 / framerate;
}
void Window::draw(Sprite& sprite)
{
	int width, height;
	glfwGetWindowSize(m_Window, &width, &height);
	sprite.draw(static_cast<float>(width), static_cast<float>(height));
}

void Window::Initialize(int major, int minor)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
void Window::Terminate()
{
	glfwTerminate();
}
void Window::KeyEventCallback(GLFWwindow* window, int key, int scancode, int action, int modes)
{
	Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (action == GLFW_PRESS)
	{
		instance->m_Keyboard.setKeyState(key, Keyboard::KeyState::PRESS);
	}
	else if (action == GLFW_RELEASE)
	{
		instance->m_Keyboard.setKeyState(key, Keyboard::KeyState::RELEASE);
	}
}
void Window::MouseEventCallback(GLFWwindow* window, int button, int action, int mods)
{
	Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (action == GLFW_PRESS)
	{
		instance->m_Mouse.setMouseState(button, Mouse::MouseState::PRESS);
	}
	else if (action == GLFW_RELEASE)
	{
		instance->m_Mouse.setMouseState(button, Mouse::MouseState::RELEASE);
	}
}

void Window::setCursorStyle(Cursor::Style style)
{
	m_Cursor.setStyle(style);
}

void Window::setCursorIcon(const char* iconPath)
{
	m_Cursor.reset();
	m_Cursor.loadFromFile(iconPath);
}

void Window::setCursorState(Cursor::State state)
{
	m_Cursor.setState(state);
}

void Window::setWindowIcon(const char* iconPath)
{
	GLFWimage icon;
	icon.pixels = stbi_load(iconPath, &icon.width, &icon.height, 0, 4);
	if (!icon.pixels)
	{
		std::cout << "Failed to load icon" << std::endl;
		return;
	}
	glfwSetWindowIcon(m_Window, 1, &icon);
}
