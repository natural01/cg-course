#pragma once
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

class CPoint
{
public:
	CPoint(float x, float y, float z);
	void SetPoint(float x, float y, float z);
	glm::dvec3 GetPoint();

private:
	glm::dvec3 m_point;
};