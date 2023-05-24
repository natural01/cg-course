#include "CHome.h"

CHome::CHome(float x, float y, float height, float width, float lon)
	: m_positionX(x)
	, m_positionY(y)
	, m_height(height)
	, m_width(width)
	, m_long(lon)
{
}

void CHome::DrawHome() const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	float vertices[8][3] =
	{
		{m_positionX, m_positionY, 0},
		{m_positionX, m_positionY + m_width, 0},
		{m_positionX, m_positionY + m_width, m_height},
		{m_positionX, m_positionY, m_height},
		{m_positionX + m_long, m_positionY, 0},
		{m_positionX + m_long, m_positionY + m_width, 0},
		{m_positionX + m_long, m_positionY + m_width, m_height},
		{m_positionX + m_long, m_positionY, m_height},
	};
	static const unsigned char faces[6][4] =
	{
		{4, 7, 3, 0},
		{1, 2, 6, 5},
		{7, 6, 2, 3},
		{0, 3, 2, 1},
		{5, 6, 7, 4},
	};
	static size_t const faceCount = sizeof(faces) / sizeof(*faces);
	glEnable(GL_TEXTURE_2D);
	int xTex = 0;
	int yTex = 0;
	glBegin(GL_QUADS);
	{
		for (size_t face = 0; face < faceCount; ++face)
		{
			for (size_t i = 0; i < 4; ++i)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
		}
	}
	glEnd();
	CRoof roof = CRoof(m_positionX, m_positionY, m_positionX + m_long, m_positionY + m_width, m_height);
	roof.Draw();
}
