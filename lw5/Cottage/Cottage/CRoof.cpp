#include "ÑRoof.h"

CRoof::CRoof(float x1, float y1, float x2, float y2, float height)
	: m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
	, m_height(height)
	, m_heightOfRoof(0.5)
{
}

void CRoof::DrawGable(float vertices[6][3], unsigned char faces[2][3]) const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 3);
	int xTex = 0;
	int yTex = 0;
	for (int face = 0; face < 2; face++)
	glBegin(GL_TRIANGLES);
	{
		for (int face = 0; face < 2; face++)
		{
			for (size_t i = 0; i < 3; i++)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; xTex = 0; continue; }
			}
		}
	}
	glEnd();
}

void CRoof::DrawRoof(float vertices[6][3], unsigned char faces[4][4]) const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	static size_t const faceCount = sizeof(faces) / sizeof(*faces);
	glEnable(GL_TEXTURE_2D);
	int xTex = 0;
	int yTex = 0;
	glBegin(GL_QUADS);
	{
		for (size_t face = 0; face < 4; ++face)
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
}

void CRoof::Draw() const
{
	const float tg = ((m_y2 - m_y1) / 2) / m_heightOfRoof;
	float verticesOfGable[6][3] =
	{
		{m_x2, m_y1, m_height},
		{m_x2, m_y2, m_height},
		{m_x2, (m_y1 + m_y2) / 2, m_height + m_heightOfRoof},
		{m_x1, m_y1, m_height},
		{m_x1, m_y2, m_height},
		{m_x1, (m_y1 + m_y2) / 2, m_height + m_heightOfRoof},
	};
	float verticesOfRoof[6][3] =
	{
		{m_x1 - 0.03, m_y2 + tg * 0.1, m_height - 0.1},
		{m_x2 + 0.03, m_y2 + tg * 0.1, m_height - 0.1},
		{m_x1 - 0.03, m_y1 - tg * 0.1, m_height - 0.1},
		{m_x2 + 0.03, m_y1 - tg * 0.1, m_height - 0.1},
		{m_x2 + 0.03, (m_y1 + m_y2) / 2, m_height + m_heightOfRoof},
		{m_x1 - 0.03, (m_y1 + m_y2) / 2, m_height + m_heightOfRoof},
	};
	static unsigned char facesOfRoof[4][4] =
	{
		{2, 3, 4, 5},
		{1, 0, 5, 4},
		{3, 2, 5, 4},
		{0, 1, 4, 5},
	};
	static unsigned char facesOfGable[2][3] =
	{
		{0, 1, 2},
		{5, 4, 3}
	};
	glEnable(GL_TEXTURE_2D);
	DrawGable(verticesOfGable, facesOfGable);
	DrawRoof(verticesOfRoof, facesOfRoof);
}