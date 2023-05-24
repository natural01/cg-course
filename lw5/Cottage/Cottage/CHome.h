#include "GL/glut.h"
#include "ÑRoof.h"
#pragma once

class CHome
{
public:
	CHome(float x, float y, float height, float width, float lon);
	void DrawHome() const;

private:
	float m_positionX;
	float m_positionY;
	float m_height;
	float m_width;
	float m_long;
};