#include "CWindow.h"
#include "CFrame.h"
#include "CLFWInitializer.cpp"

int main()
{
	GLFWInitializer initGLFW;
	Window *window = Window::GetInstance(1900, 1600, "lw4");
	window->Run();
}