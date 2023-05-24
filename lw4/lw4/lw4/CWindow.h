#pragma once
#define _USE_MATH_DEFINES
#include "CBaseWindow.h"
#include "CMap.h"
#include "CPoint.h"
#include <stdlib.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "CFrame.h"
#include "CLFWInitializer.cpp"
#include "CCarner.h"

#include "CPlayer.h"

class Window
{
public:
	static Window* GetInstance(int w, int h, const char* title) {
		if (instance == nullptr) {
			instance = new Window(w, h, title);
		}
		return instance;
	}
	void Run();
	/*CPoint GetCameraPosition();
	void SetCameraPosition(CPoint newPosition);*/
	GLFWwindow* GetWindow();
	/*void GoFront();
	void GoBack();
	void GoLeft();
	void GoRight();
	CCarner *GetCarnerOfCamera();
	bool GetMouseButtonState();
	void SetMouseButtonState(bool state);
	void SetRotateX(float rotateX);
	void SetRotateY(float rotateY);*/

private:
	static Window* instance;
	Window(int w, int h, const char* title);

	void OnRunStart();
	void Draw(int width, int height);
	/*GLFWkeyfun SetKeyCallback();
	GLFWcursorposfun SetCursorCallback();
	GLFWmousebuttonfun SetMouseButtonCallback();*/
	static void SetupProjectionMatrix(int width, int height);
	void SetupCameraMatrix();
	/*void RotateCamera(GLfloat rotateX, GLfloat rotateY);*/

	static GLFWwindow* MakeWindow(int w, int h, const char* title)
	{
		glfwWindowHint(GLFW_DEPTH_BITS, 24);
		return glfwCreateWindow(w, h, title, nullptr, nullptr);
	}

	GLFWwindow* m_window;
	CMap m_map = CMap();/*
	CPoint m_cameraPosition = CPoint(-0.9, 0.2, 0.7);
	CPoint m_mainPosition = CPoint(0.0, 0.0, 0.0);
	CPoint m_direction = CPoint(0.0, 0.0, 1.0);*/
	CPlayer* m_player = new CPlayer(m_window);
	//bool m_mouseButtonState = false;
	//CCarner m_carnerOfCamera = CCarner();
	//float m_rotateX = 0.0;
	//float m_rotateY = 0.0;
};