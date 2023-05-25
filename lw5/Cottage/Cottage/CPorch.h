#include "ÑRoof.h"

#pragma once
class CPorch
{
public:
	CPorch(float x, float y);
	void Draw() const;
	void SetPosition(float x, float y);

private:
	float m_x;
	float m_y;
	float m_height;
	float m_width;
	
	void DrawRoof() const;
	void DrawStairs() const;
	void DrawPillar() const;
};