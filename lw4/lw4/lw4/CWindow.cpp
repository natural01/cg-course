#include "CWindow.h"
#include <iostream>

//void KeyCallback(GLFWwindow* window, int key, int scancode, int actions, int mods)
//{
//	Window* newWindow = Window::GetInstance(1, 1, "");
//	switch (key)
//	{
//	case GLFW_KEY_W:
//		newWindow->GoFront();
//		break;
//	case GLFW_KEY_A:
//		newWindow->GoLeft();
//		break;
//	case GLFW_KEY_S:
//		newWindow->GoBack();
//		break;
//	case GLFW_KEY_D:
//		newWindow->GoRight();
//		break;
//	}
//}
//void CursorCallback(GLFWwindow* window, double xPos, double yPos)
//{
//	Window* newWindow = Window::GetInstance(1, 1, "");
//	if (newWindow->GetMouseButtonState())
//	{
//		newWindow->GetCarnerOfCamera()->CheckChangeCarner(xPos);
//		newWindow->SetRotateX(sin(newWindow->GetCarnerOfCamera()->GetCarner()));
//		newWindow->SetRotateY(-cos(newWindow->GetCarnerOfCamera()->GetCarner()));
//	}
//}
//
//void MouseButtonCallback(GLFWwindow* window, int button, int action, int mode)
//{
//	Window* newWindow = Window::GetInstance(1, 1, "");
//	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
//	{
//		newWindow->SetMouseButtonState(true);
//	}
//	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
//	{
//		newWindow->SetMouseButtonState(false);
//	}
//}

Window* Window::instance = nullptr;
Window::Window(int w, int h, const char* title)
	: m_window{ MakeWindow(w, h, title) }
{
	if (!m_window)
	{
		throw std::runtime_error("Failed to create window");
	}
}

void Window::Run()
{
	glfwMakeContextCurrent(m_window);
	OnRunStart();
	/*SetKeyCallback();
	SetCursorCallback();
	SetMouseButtonCallback();*/
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	while (!glfwWindowShouldClose(m_window))
	{
		int w, h;
		glfwGetFramebufferSize(m_window, &w, &h);
		Draw(w, h);
		glFinish();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

void Window::OnRunStart()
{
	glClearColor(1, 1, 1, 1);
}

GLFWwindow* Window::GetWindow()
{
	return m_window;
}

//GLFWkeyfun Window::SetKeyCallback()
//{
//	return glfwSetKeyCallback(GetWindow(), KeyCallback);
//}
//GLFWcursorposfun Window::SetCursorCallback()
//{
//	return glfwSetCursorPosCallback(GetWindow(), CursorCallback);
//}
//GLFWmousebuttonfun Window::SetMouseButtonCallback()
//{
//	return glfwSetMouseButtonCallback(GetWindow(), MouseButtonCallback);
//}

void Window::Draw(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupProjectionMatrix(width, height);

	SetupCameraMatrix();
	glEnable(GL_DEPTH_TEST);

	CFrame frame;
	frame.Draw();

	m_map.Draw();
}

void Window::SetupProjectionMatrix(int width, int height)
{
	glViewport(0, 0, width, height);

	double aspect = double(width + 1000) / double(height + 1000);

	glMatrixMode(GL_PROJECTION);
	
	const double FRUSTUM_SIZE = 2;
	double frustumHeight = FRUSTUM_SIZE;
	double frustumWidth = frustumHeight * aspect;

	glLoadIdentity();
	glFrustum(
		-frustumWidth * 0.5, frustumWidth * 0.5,	// left, right
		-frustumHeight * 0.5, frustumHeight * 0.5,	// top, bottom
		FRUSTUM_SIZE * 0.5, FRUSTUM_SIZE * 20		// znear, zfar
	);
}

void Window::SetupCameraMatrix()
{
	gluLookAt
	(
		m_player->GetCameraPosition()->GetPoint().x, m_player->GetCameraPosition()->GetPoint().y, m_player->GetCameraPosition()->GetPoint().z,
		m_player->GetCameraPosition()->GetPoint().x + sin(m_player->GetCarnerOfCamera()), m_player->GetCameraPosition()->GetPoint().y - cos(m_player->GetCarnerOfCamera()), m_player->GetCameraPosition()->GetPoint().z,
		m_player->GetDirection()->GetPoint().x, m_player->GetDirection()->GetPoint().y, m_player->GetDirection()->GetPoint().z
	);
}

//CPoint Window::GetCameraPosition()
//{
//	return m_cameraPosition;
//}
//void Window::SetCameraPosition(CPoint newPosition)
//{
//	m_cameraPosition = newPosition;
//}
//void Window::GoFront()
//{
//	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x + m_rotateX * 0.1, m_cameraPosition.GetPoint().y + m_rotateY * 0.1, m_cameraPosition.GetPoint().z);
//}
//void Window::GoBack()
//{
//	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x - m_rotateX * 0.1, m_cameraPosition.GetPoint().y - m_rotateY * 0.1, m_cameraPosition.GetPoint().z);
//}
//void Window::GoLeft()
//{
//	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x - sin(m_carnerOfCamera.GetCarner() + 80.0) * 0.1, m_cameraPosition.GetPoint().y + cos(m_carnerOfCamera.GetCarner() + 80.0) * 0.1, m_cameraPosition.GetPoint().z);
//}
//void Window::GoRight()
//{
//	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x + sin(m_carnerOfCamera.GetCarner() + 80.0) * 0.1, m_cameraPosition.GetPoint().y - cos(m_carnerOfCamera.GetCarner() + 80.0) * 0.1, m_cameraPosition.GetPoint().z);
//}
//
//CCarner* Window::GetCarnerOfCamera()
//{
//	return &m_carnerOfCamera;
//}
//
//bool Window::GetMouseButtonState()
//{
//	return m_mouseButtonState;
//}
//void Window::SetMouseButtonState(bool state)
//{
//	m_mouseButtonState = state;
//}
//
//void Window::SetRotateX(float rotateX)
//{
//	m_rotateX = rotateX;
//}
//void Window::SetRotateY(float rotateY)
//{
//	m_rotateY = rotateY;
//}