#include "CVertices.h"

CVertices::CVertices(float x, float y, float z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
{
}

float CVertices::GetX()
{
	return m_x;
}
float CVertices::GetY()
{
	return m_y;
}
float CVertices::GetZ()
{
	return m_z;
}