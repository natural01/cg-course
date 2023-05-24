#pragma once

class CCarner
{
public:
	CCarner() {}

	double GetCarner();
	void CheckChangeCarner(double yPos);

private:
	double m_cornerOfCamera = 0.0;
	double m_xPos = 0.0;
};