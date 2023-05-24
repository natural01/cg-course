#include "CCarner.h"
#include <iostream>

void CCarner::CheckChangeCarner(double xPos)
{
	if (m_xPos == 0.0)
	{
		m_xPos = xPos;
		return;
	}
	if (m_xPos < xPos)
	{
		if (m_cornerOfCamera != 359.0) { m_cornerOfCamera = m_cornerOfCamera - 0.1; }
		else { m_cornerOfCamera = 0.0; }
		m_xPos = xPos;
		return;
	}
	if (m_xPos > xPos)
	{
		if (m_cornerOfCamera != 0.0) { m_cornerOfCamera = m_cornerOfCamera + 0.1; }
		else { m_cornerOfCamera = 359.0; }
		m_xPos = xPos;
		return;
	}
}

double CCarner::GetCarner()
{
	return m_cornerOfCamera;
}