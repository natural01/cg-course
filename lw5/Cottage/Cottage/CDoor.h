#include "GL/glut.h"
#include "IHouseElement.h"

#pragma once
class CDoor : public IHouseElement
{
public:
	CDoor(float x1, float y1, float x2, float y2);
	void Draw() const override;

private:
	float m_x1;
	float m_y1;
	float m_x2;
	float m_y2;
	float m_height;
};