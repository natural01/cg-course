#include "CPoint.h"

CPoint::CPoint(float x, float y, float z)
	: m_point(glm::dvec3(x, y, z))
{
}

void CPoint::SetPoint(float x, float y, float z)
{
	m_point = glm::dvec3(x, y, z);
}

glm::dvec3 CPoint::GetPoint()
{
	return m_point;
}