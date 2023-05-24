#include "GL/glut.h"
#pragma once

class CPlayer
{
public:
	CPlayer();
	~CPlayer(void);

	double GetCoordX();
	void SetCoordX(double cX);
	double GetCoordY();	
	void SetCoordY(double cY);
	double GetCoordZ();
	void SetCoordZ(double cZ);
	
	double GetDirectionX();
	void SetDirectionX(double cX);

	double GetDirectionZ();
	void SetDirectionZ(double cZ);

	double GetAngle();
	void SetAngle(double angle);

	double GetSpeed();
private:
	double m_X;
	double m_Y;
	double m_Z;

	double m_angle;

	double m_directionX;
	double m_directionZ;

	float m_speed;
};

