#include "GL/glut.h"
#include "ÑRoof.h"
#include "CPorch.h"
#include <vector>
#pragma once

class CHome
{
public:
	CHome(float x, float y, float height, float width, float lon);
	void DrawHome() const;
	void AddPorch();
	void SetPorchPosition(float x, float y, int countOfPorch);

private:
	float m_positionX;
	float m_positionY;
	float m_height;
	float m_width;
	float m_long;

	std::vector<CPorch> m_porches;
};