#include "CHome.h"
#include <stdexcept>

CHome::CHome(float x, float y, float height, float width, float lon)
	: m_positionX(x)
	, m_positionY(y)
{
	if (height < 1.0 || lon < 1.0 || height < 1.0)
	{
		std::runtime_error("wrong house size");
	}
	m_height = height;
	m_width = width;
	m_long = lon;
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
	DrawRoof();
	DrawPorch();
	DrawDoor();
	DrawWindow();
	DrawGates();
}

void CHome::AddPorch()
{
	m_porches.push_back(std::make_unique<CPorch>(0.0, 0.0));
}

void CHome::AddDoor(float x1, float y1, float x2, float y2)
{
	m_doors.push_back(std::make_unique<CDoor>(x1, y1, x2, y2));
}

void CHome::AddWindow(float x1, float y1, float x2, float y2)
{
	m_windows.push_back(std::make_unique<CWindow>(x1, y1, x2, y2));
}

void CHome::AddGate(float x1, float y1, float x2, float y2)
{
	m_gates.push_back(std::make_unique<CGate>(x1, y1, x2, y2, m_height - 0.1));
}

void CHome::DrawPorch() const
{
	if (m_porches.size() > 0)
	{
		for (const auto& porch : m_porches)
		{
			porch->Draw();
		}
	}
}

void CHome::DrawRoof() const
{
	CRoof roof = CRoof(m_positionX, m_positionY, m_positionX + m_long, m_positionY + m_width, m_height);
	roof.Draw();
}

void CHome::DrawDoor() const
{
	if (m_doors.size() > 0)
	{
		for (const auto& door : m_doors)
		{
			door->Draw();
		}
	}
}

void CHome::DrawWindow() const
{
	if (m_windows.size() > 0)
	{
		for (const auto& window : m_windows)
		{
			window->Draw();
		}
	}
}

void CHome::DrawGates() const
{
	if (m_gates.size() > 0)
	{
		for (const auto& gate: m_gates)
		{
			gate->Draw();
		}
	}
}

void CHome::SetPorchPosition(float x, float y, int countOfPorch)
{
	m_porches[countOfPorch - 1]->SetPosition(x, y);
}