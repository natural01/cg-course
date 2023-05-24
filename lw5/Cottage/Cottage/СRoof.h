#include "GL/glut.h"
#pragma once

class CRoof
{
public:
	CRoof(float x1, float y1, float x2, float y2, float height);
	void Draw() const;

private:
	void DrawGable(float vertices[6][3], unsigned char faces[2][3]) const;
	void DrawRoof(float vertices[6][3], unsigned char faces[4][4]) const;
	float m_x1;
	float m_x2;
	float m_y1;
	float m_y2;
	float m_height;
	float m_heightOfRoof;
};