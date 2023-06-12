#include "CPorch.h"

CPorch::CPorch(float x, float y)
	: m_x(x)
	, m_y(y)
	, m_height(0.6)
	, m_width(0.5)
{
}

void CPorch::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CPorch::DrawRoof() const
{
	CRoof roof = CRoof(m_x, m_y-0.2, m_x + m_width, m_y+0.2, m_height);
	roof.Draw();
}
void CPorch::DrawStairs() const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	float vertices1[8][3] =
	{
		{m_x, m_y, 0},
		{m_x+m_width, m_y, 0},
		{m_x+m_width, m_y, 0.1},
		{m_x, m_y, 0.1},
		{m_x, m_y - 0.25, 0},
		{m_x + m_width, m_y - 0.25, 0},
		{m_x + m_width, m_y - 0.25, 0.1},
		{m_x, m_y - 0.25, 0.1},
	};
	float vertices2[8][3] =
	{
		{m_x, m_y - 0.25, 0},
		{m_x + m_width, m_y - 0.25, 0},
		{m_x + m_width, m_y - 0.25, 0.05},
		{m_x, m_y - 0.25, 0.05},
		{m_x, m_y - 0.35, 0},
		{m_x + m_width, m_y - 0.35, 0},
		{m_x + m_width, m_y - 0.35, 0.05},
		{m_x, m_y - 0.35, 0.05},
	};
	static const unsigned char faces[6][4] =
	{
		{4, 7, 3, 0},
		{1, 2, 6, 5},
		{4, 0, 1, 5},
		{7, 6, 2, 3},
		{0, 3, 2, 1},
		{4, 5, 6, 7},

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
				glVertex3fv(vertices1[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
		}
	}
	glEnd();
	glBegin(GL_QUADS);
	{
		for (size_t face = 0; face < faceCount; ++face)
		{
			for (size_t i = 0; i < 4; ++i)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices2[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
		}
	}
	glEnd();
}
void CPorch::DrawPillar() const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	float vertices1[8][3] =
	{
		{m_x, m_y - 0.1, 0},
		{m_x + 0.05, m_y - 0.1, 0},
		{m_x + 0.05, m_y - 0.1, m_height},
		{m_x, m_y - 0.1, m_height},
		{m_x, m_y - 0.15, 0},
		{m_x + 0.05, m_y - 0.15, 0},
		{m_x + 0.05, m_y - 0.15, m_height},
		{m_x, m_y - 0.15, m_height},
	};
	float vertices2[8][3] =
	{
		{m_x + float(0.45), m_y - float(0.1), 0},
		{m_x + m_width, m_y - float(0.1), 0},
		{m_x + m_width, m_y - float(0.1), m_height},
		{m_x + float(0.45), m_y - float(0.1), m_height},
		{m_x + float(0.45), m_y - float(0.15), 0},
		{m_x + m_width, m_y - float(0.15), 0},
		{m_x + m_width, m_y - float(0.15), m_height},
		{m_x + float(0.45), m_y - float(0.15), m_height},
	};
	static const unsigned char faces[6][4] =
	{
		{4, 7, 3, 0},
		{1, 2, 6, 5},
		{4, 0, 1, 5},
		{7, 6, 2, 3},
		{0, 3, 2, 1},
		{4, 5, 6, 7},

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
				glVertex3fv(vertices1[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
		}
	}
	glEnd();
	glBegin(GL_QUADS);
	{
		for (size_t face = 0; face < faceCount; ++face)
		{
			for (size_t i = 0; i < 4; ++i)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices2[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
		}
	}
	glEnd();
}

void CPorch::Draw() const
{
	DrawRoof();
	DrawStairs();
	DrawPillar();
	CDoor door = CDoor(m_x + 0.1, m_y-0.01, m_x + m_width - 0.1, m_y-0.01);
	door.Draw();
}