#pragma once
#include <GLFW/glfw3.h>
#include <chrono>
#include <stdexcept>
#include "CWall.h"
#include <vector>

class CMap
{
public: 
	CMap()
	{
		m_walls.push_back(new CWall(-m_mapsSize / 2, m_mapsSize / 2, m_wallsHeight, m_mapsSize, m_latitudeWall));
		m_walls.push_back(new CWall(-m_mapsSize / 2, -m_mapsSize / 2, m_wallsHeight, m_mapsSize, m_latitudeWall));
		m_walls.push_back(new CWall(m_mapsSize / 2, -m_mapsSize / 2, m_wallsHeight, m_latitudeWall, m_mapsSize));
		m_walls.push_back(new CWall(-m_mapsSize / 2, -m_mapsSize / 2, m_wallsHeight, m_latitudeWall, m_mapsSize));
	}
	void Draw();
	void DrawWalls();

private:
	float m_mapsSize = 16.0;
	float m_wallsHeight = 3.0;
	float m_latitudeWall = 0.2;
	std::vector<CWall*> m_walls;
};