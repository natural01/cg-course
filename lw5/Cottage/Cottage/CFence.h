#include "GL/glut.h"
#pragma once

class CFence
{
public:
	CFence(float x1, float y1, float x2, float y2);
	void DrawFence() const;

private:
	void DrawRightSide() const;
	void DrawLeftSide() const;
	void DrawBackSide() const;

	float m_x1;
	float m_x2;
	float m_y1;
	float m_y2;
	float m_heightOfFence;
};