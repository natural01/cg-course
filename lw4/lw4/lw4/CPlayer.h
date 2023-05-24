#pragma once
#include "CCarner.h"
#include "CPoint.h"
#include <GLFW/glfw3.h>

class CPlayer
{
public:
	CPlayer(GLFWwindow* window);

	double GetCarnerOfCamera();

	CPoint* GetCameraPosition();
	CPoint* GetMainPosition();
	CPoint* GetDirection();

private:
	void GoFront();
	void GoBack();
	void MoveLeft();
	void MoveRight();
	static void KeyCallback(unsigned char key, int x, int y);
	void SetKeyCallback();

	GLFWwindow* m_window;

	CPoint m_cameraPosition = CPoint(-0.9, 0.2, 0.7);
	CPoint m_mainPosition = CPoint(0.0, 0.0, 0.0);
	CPoint m_direction = CPoint(0.0, 0.0, 1.0);
	static CPlayer* m_player;
	float m_rotateX = 0.0;
	float m_rotateY = 0.0;
	double m_carnerOfCamera = 0.0;
};