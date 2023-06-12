#pragma once

class CVertices
{
public:
	CVertices(float x, float y, float z);
	float GetX();
	float GetY();
	float GetZ();

private:
	float m_x;
	float m_y;
	float m_z;
};