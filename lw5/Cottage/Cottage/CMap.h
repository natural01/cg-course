#include "GL/glut.h"
#include "CHome.h"
#include "CFence.h"

#pragma once
class CMap
{
public:
	CMap();
	void DrawMap() const;
private:
	const float m_mapSize = 10;
	CHome m_home = CHome(-0.5, 0.0, 1.0, 1.5, 2.0);
	CHome m_garage = CHome(-1.5, 0.25, 0.75, 1.0, 1.0);
	CFence m_fence = CFence(-3.5, 2.5, 2.5, -1.0);
};
