#include "CWindow.h"
#include "CFrame.h"
#include "CLFWInitializer.cpp"

int main()
{
	GLFWInitializer initGLFW;
	Window window{ 800, 600, "lw4" };
	window.Run();
}