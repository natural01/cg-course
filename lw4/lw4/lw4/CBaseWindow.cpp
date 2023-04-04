#include "CBaseWindow.h"

BaseWindow::BaseWindow(int w, int h, const char* title)
	: m_window{ MakeWindow(w, h, title) }
{
	if (!m_window)
	{
		throw std::runtime_error("Failed to create window");
	}
}

BaseWindow::~BaseWindow()
{
	glfwDestroyWindow(m_window);
}

void BaseWindow::Run()
{
	glfwMakeContextCurrent(m_window);
	OnRunStart();
	while (!glfwWindowShouldClose(m_window))
	{
		int w, h;
		glfwGetFramebufferSize(m_window, &w, &h);
		Draw(w, h);
		glFinish();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	OnRunEnd();
}