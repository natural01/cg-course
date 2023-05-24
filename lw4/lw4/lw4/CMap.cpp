#include "CMap.h"

void CMap::DrawWalls()
{
	//m_walls.push_back(new CWall(m_mapsSize / 2, -m_mapsSize / 4, m_wallsHeight, -m_mapsSize / 2, m_latitudeWall));
	//m_walls.push_back(new CWall(0.0, -m_mapsSize / 4, m_wallsHeight, m_latitudeWall, m_mapsSize/4));
	//m_walls.push_back(new CWall(-m_mapsSize / 4, -m_mapsSize / 2, m_wallsHeight, m_latitudeWall, m_mapsSize / 2));
	//m_walls.push_back(new CWall(m_mapsSize / 4, m_mapsSize / 4, m_wallsHeight, m_mapsSize / 4, m_latitudeWall));
	//m_walls.push_back(new CWall(-m_mapsSize / 4, m_mapsSize / 4, m_wallsHeight, m_mapsSize / 4, m_latitudeWall));
	//m_walls.push_back(new CWall(-m_mapsSize / 4, m_mapsSize / 4, m_wallsHeight, m_latitudeWall, m_mapsSize / 4));
	m_walls.push_back(new CWall(m_mapsSize / 5, m_mapsSize / 9, m_wallsHeight, m_mapsSize / 5, m_mapsSize / 6));
	m_walls.push_back(new CWall(m_mapsSize / 5, -m_mapsSize / 5, m_wallsHeight, m_mapsSize / 5, m_mapsSize / 6));
	for (const auto wall : m_walls)
		wall->Draw();
}

void CMap::Draw()
{
	glTranslatef(0, 0, 0);
	glRotatef(0, 0, 0, 0);
	// Рисуем красный квадрат в плоскости XOY
	glColor3f(0.555, 0.523, 0.496);
	glRectf(-m_mapsSize / static_cast<GLfloat>(2), -m_mapsSize / static_cast<GLfloat>(2), m_mapsSize / static_cast<GLfloat>(2), m_mapsSize / static_cast<GLfloat>(2));
	DrawWalls();
}