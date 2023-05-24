#include "CWall.h"
#include <stdexcept>

CWall::CWall(float x, float y, float height, float width, float latitude)
	: m_startWallPos(CPoint(x, y, height))
	, m_height(height)
	, m_width(width)
	, m_latitude(latitude)
{
	SetSideColor(CS_NEGATIVE_X, 255, 0, 0);
	SetSideColor(CS_POSITIVE_X, 0, 255, 0);
	SetSideColor(CS_NEGATIVE_Y, 0, 0, 255);
	SetSideColor(CS_POSITIVE_Y, 255, 255, 0);
	SetSideColor(CS_NEGATIVE_Z, 0, 255, 255);
	SetSideColor(CS_POSITIVE_Z, 255, 0, 255);
}

CWall::~CWall()
{
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
	float vertices[8][3] =
	{
		{(float)m_startWallPos.GetPoint().x + m_width, (float)m_startWallPos.GetPoint().y, 0},
		{(float)m_startWallPos.GetPoint().x + m_width, (float)m_startWallPos.GetPoint().y + m_latitude, 0},
		{(float)m_startWallPos.GetPoint().x + m_width, (float)m_startWallPos.GetPoint().y + m_latitude, m_height},
		{(float)m_startWallPos.GetPoint().x + m_width, (float)m_startWallPos.GetPoint().y, m_height},
		{(float)m_startWallPos.GetPoint().x, (float)m_startWallPos.GetPoint().y, 0},
		{(float)m_startWallPos.GetPoint().x, (float)m_startWallPos.GetPoint().y + m_latitude, 0},
		{(float)m_startWallPos.GetPoint().x, (float)m_startWallPos.GetPoint().y + m_latitude, m_height},
		{(float)m_startWallPos.GetPoint().x, (float)m_startWallPos.GetPoint().y, m_height},
	};
	const unsigned char faces[6][4] =
	{
		{4, 7, 3, 0},	// грань x<0
		{5, 1, 2, 6},	// грань x>0
		{0, 3, 2, 1},	// грань z<0
		{4, 5, 6, 7},	// грань z>0
	};
	size_t const faceCount = sizeof(faces) / sizeof(*faces);

	//glColor3f(0.755, 0.723, 0.696);
	glCullFace(GL_FRONT);
	glBegin(GL_QUADS);
	{
		for (size_t face = 0; face < faceCount; ++face)
		{
			glColor4ubv(m_sideColors[face]);

			for (size_t i = 0; i < 4; ++i)
			{
				size_t vertexIndex = faces[face][i];
				glVertex3fv(vertices[vertexIndex]);
			}
		}
	}
	glEnd();
}