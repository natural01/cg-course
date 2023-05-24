//#pragma once
//#define _USE_MATH_DEFINES
//#include <glm/ext/matrix_clip_space.hpp>
//#include <glm/ext/matrix_transform.hpp>
//#include "CFrame.h"
//#include "CLFWInitializer.cpp"
//
//class BaseWindow
//{
//public:
//	BaseWindow(int w, int h, const char* title);
//
//	BaseWindow(const BaseWindow&) = delete;
//	BaseWindow& operator=(const BaseWindow&) = delete;
//
//	virtual ~BaseWindow();
//	void Run();
//	GLFWwindow* GetWindow();
//
//private:
//	virtual void Draw(int width, int height) = 0;
//
//	virtual GLFWkeyfun SetKeyCallback() = 0;
//	virtual void OnRunStart() {}
//	virtual void OnRunEnd() {}
//
//	static GLFWwindow* MakeWindow(int w, int h, const char* title)
//	{
//		glfwWindowHint(GLFW_DEPTH_BITS, 24);
//		return glfwCreateWindow(w, h, title, nullptr, nullptr);
//	}
//	GLFWwindow* m_window;
//};