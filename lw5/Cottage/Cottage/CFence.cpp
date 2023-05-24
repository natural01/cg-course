#include "CFence.h"

CFence::CFence(float x1, float y1, float x2, float y2)
	: m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
	, m_heightOfFence(0.3)
{
}

void CFence::DrawLeftSide() const
{
	float vertices[4][3] =
	{
		{m_x1, m_y1, 0.0},
		{m_x1, m_y2, 0.0},
		{m_x1, m_y2, m_heightOfFence},
		{m_x1, m_y1, m_heightOfFence},
	};

	static const unsigned char faces[2][4] =
	{
		{3, 0, 1, 2},
		{2, 1, 0, 3},
	};

	int xTex = 0;
	int yTex = 0;
	glEnable(GL_TEXTURE_2D);
	for (size_t face = 0; face < 2; ++face)
	{
		glBindTexture(GL_TEXTURE_2D, 4);

		glBegin(GL_QUADS);
		{
			for (size_t i = 0; i < 4; i++)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
			glEnd();
		}
	}
}

void CFence::DrawRightSide() const
{
	float vertices[4][3] =
	{
		{m_x2, m_y1, 0.0},
		{m_x2, m_y2, 0.0},
		{m_x2, m_y2, m_heightOfFence},
		{m_x2, m_y1, m_heightOfFence},
	};

	static const unsigned char faces[2][4] =
	{
		{3, 0, 1, 2},
		{2, 1, 0, 3},
	};

	int xTex = 0;
	int yTex = 0;
	glEnable(GL_TEXTURE_2D);
	for (size_t face = 0; face < 2; ++face)
	{
		glBindTexture(GL_TEXTURE_2D, 4); 

		glBegin(GL_QUADS);
		{
			for (size_t i = 0; i < 4; i++)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
			glEnd();
		}
	}
}

void CFence::DrawBackSide() const
{
	float vertices[4][3] =
	{
		{m_x1, m_y1, 0.0},
		{m_x2, m_y1, 0.0},
		{m_x2, m_y1, m_heightOfFence},
		{m_x1, m_y1, m_heightOfFence},
	};

	static const unsigned char faces[2][4] =
	{
		{3, 0, 1, 2},
		{2, 1, 0, 3},
	};

	int xTex = 0;
	int yTex = 0;
	glEnable(GL_TEXTURE_2D);
	for (size_t face = 0; face < 2; ++face)
	{
		glBindTexture(GL_TEXTURE_2D, 4);

		glBegin(GL_QUADS);
		{
			for (size_t i = 0; i < 4; i++)
			{
				size_t vertexIndex = faces[face][i];
				glTexCoord2f(xTex, yTex);
				glVertex3fv(vertices[vertexIndex]);
				if (xTex == 0 && yTex == 0) { yTex = 1; continue; }
				if (xTex == 0 && yTex == 1) { xTex = 1; continue; }
				if (xTex == 1 && yTex == 1) { yTex = 0; continue; }
				if (xTex == 1 && yTex == 0) { xTex = 0; break; }
			}
			glEnd();
		}
	}
}

void CFence::DrawFence() const
{
	DrawRightSide();
	DrawLeftSide();
	DrawBackSide();
}