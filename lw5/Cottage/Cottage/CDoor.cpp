#include "GL/glut.h"

class CDoor
{
public:
	CDoor(float x, float y)
		: m_x(x)
		, m_y(y)
	{
	}

	void Draw();

private:
	float m_x;
	float m_y;
};