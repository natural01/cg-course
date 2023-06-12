#include "CMap.h"
#include "glm/glm.hpp"

CMap::CMap()
{
	m_home.AddPorch();
	m_home.SetPorchPosition(0.0, 0.0, 1);
	m_home.AddWindow(0.6, -0.01, 1.1, -0.01);
	m_home.AddWindow(1.51, 0.16, 1.51, 0.66);
	m_home.AddWindow(1.51, 0.82, 1.51, 1.32);
	m_home.AddWindow(-0.3, 1.51, 0.2, 1.51);
	m_home.AddWindow(0.5, 1.51, 1.0, 1.51);
	m_garage.AddDoor(-1.25, 0.24, -0.75, 0.24);
	m_garage.AddWindow(-1.25, 1.26, -0.75 , 1.26);
	m_garage.AddGate(-1.51, 1.0, -1.51, 0.5);
}

void CMap::DrawMap() const
{
	GLfloat frontColor[] = { 0, 0, 0, 1 };
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, frontColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);

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