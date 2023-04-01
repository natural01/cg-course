#include "GLFWInitializer.cpp"
#include "CWindow.h"

int main()
{
	GLFWInitializer initGLFW;
	Window window{ 1000, 1000, "Hello, triangle" };
	window.Run();
}