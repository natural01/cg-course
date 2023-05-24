#include "CMap.h"

CMap::CMap()
{
}

void CMap::DrawMap() const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	float vertices[4][3] =
	{
		{-m_mapSize / 2, -m_mapSize / 2, 0.0},
		{-m_mapSize / 2, m_mapSize / 2, 0.0},
		{m_mapSize / 2, m_mapSize / 2, 0.0},
		{m_mapSize / 2, -m_mapSize / 2, 0.0}
	};

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);
		glVertex3fv(vertices[0]);
		glTexCoord2f(0, 1);
		glVertex3fv(vertices[3]);
		glTexCoord2f(1, 1);
		glVertex3fv(vertices[2]);
		glTexCoord2f(1, 0);
		glVertex3fv(vertices[1]);
		glEnd();
	}
	m_home.DrawHome();
	m_garage.DrawHome();
	m_fence.DrawFence();
}