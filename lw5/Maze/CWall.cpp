#include "CWall.h"

CWall::CWall(float x, float y, float z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
	, m_size(2)
{
	SetSideColor(CS_NEGATIVE_X, 255, 255, 255);
	SetSideColor(CS_POSITIVE_X, 255, 255, 255);
	SetSideColor(CS_NEGATIVE_Y, 255, 255, 255);
	SetSideColor(CS_POSITIVE_Y, 255, 255, 255);
	SetSideColor(CS_NEGATIVE_Z, 255, 255, 255);
	SetSideColor(CS_POSITIVE_Z, 255, 255, 255);
}

void CWall::SetSideColor(
	CubeSide side, GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
	if (side < CS_MIN_CUBE_SIDE_INDEX || side > CS_MAX_CUBE_SIDE_INDEX)
	{
		throw std::invalid_argument("Invalid cube side");
	}

	m_sideColors[side][0] = r;
	m_sideColors[side][1] = g;
	m_sideColors[side][2] = b;
	m_sideColors[side][3] = a;
}

void CWall::Draw()
{
	// ������ ��������� ������
	float vertices[8][3] =
	{
		{m_x, m_y, m_z},							// 0
		{m_x + m_size, m_y, m_z},					// 1
		{m_x + m_size, m_y + m_size, m_z},			// 2
		{m_x, m_y + m_size, m_z},					// 3
		{m_x, m_y, m_z + m_size},					// 4
		{m_x + m_size, m_y, m_z + m_size},			// 5
		{m_x + m_size, m_y + m_size, m_z + m_size},	// 6
		{m_x, m_y + m_size, m_z + m_size},			// 7
	};

	// ������ ��������� ������ (� �������, ����������� � 
	// �������� ���������� �� � ������� ������)
	// ������� ������ ������ ������������� � ������� �� ������
	// ������ ������� ������� (���� �������� �� ����� �������)
	static const unsigned char faces[6][4] =
	{
		{4, 7, 3, 0},	// ����� x<0
		{5, 1, 2, 6},	// ����� x>0
		{4, 0, 1, 5},	// ����� y<0
		{7, 6, 2, 3},	// ����� y>0
		{0, 3, 2, 1},	// ����� z<0
		{4, 5, 6, 7},	// ����� z>0
	};
	static size_t const faceCount = sizeof(faces) / sizeof(*faces);

	// ��������

	int xTex = 0;
	int yTex = 0;
	// �������� ����� ��������� ��������
	glEnable(GL_TEXTURE_2D);

		GLuint countOfTexture = 0;
		for (size_t face = 0; face < faceCount; ++face)
		{
			// � ������ �������� ���������� ������
			glBindTexture(GL_TEXTURE_2D, countOfTexture); // ������� �� glBegin
			// ������������� ���� �����
			//glColor4ubv(m_sideColors[face]);

			glBegin(GL_QUADS);
			{

			// ������ ��������������� �����, ���������� �� �������
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
			if (countOfTexture < 3) { countOfTexture++; }
			else { countOfTexture = 0; }
			glEnd();
		}
	}
}