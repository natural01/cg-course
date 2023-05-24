#pragma once
#include "CPoint.h"
#include <GLFW/glfw3.h>
#include <vector>

class CWall
{
public:
	enum CubeSide
	{
		CS_NEGATIVE_X,
		CS_POSITIVE_X,
		CS_NEGATIVE_Y,
		CS_POSITIVE_Y,
		CS_NEGATIVE_Z,
		CS_POSITIVE_Z,

		CS_MIN_CUBE_SIDE_INDEX = CS_NEGATIVE_X,
		CS_MAX_CUBE_SIDE_INDEX = CS_POSITIVE_Z,
	};

	CWall(float x, float y, float height, float width, float latitude);
	~CWall();
	void Draw();
	static float vertices[8][3];

	void SetSideColor(CubeSide side, GLubyte r, GLubyte g, GLubyte b, GLubyte a = 255);

private:
	CPoint m_startWallPos;
	float m_height;
	float m_width;
	float m_latitude;
	GLubyte m_sideColors[6][4];
};