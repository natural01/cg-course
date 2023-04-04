#pragma once
#include <windows.h>
//
#include <GLFW/glfw3.h>
#include <chrono>
#include <gl/GLU.h>

class CFrame
{
public:
	CFrame(float size = 3, float endSize = 0.1);
	
	void Draw(void)const;
private:
	float m_size;
	float m_endSize;
};