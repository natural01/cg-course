#include "CPlayer.h"

CPlayer::CPlayer()
	: m_X(3)
	, m_Y(1)
	, m_Z(29)
	, m_speed(0.1)
	, m_angle(0.5)
	, m_directionX(0)
	, m_directionZ(-1)
{
}

CPlayer::~CPlayer(void)
{
}

double CPlayer::GetCoordX()
{
	return m_X;
}

double CPlayer::GetCoordY()
{
	return m_Y;
}

double CPlayer::GetCoordZ()
{
	return m_Z;
}

void CPlayer::SetCoordX(double cX)
{
	m_X = cX;
}
void CPlayer::SetCoordY(double cY)
{
	m_Y = cY;
}
void CPlayer::SetCoordZ(double cZ)
{
	m_Z = cZ;
}

double CPlayer::GetDirectionX()
{
	return m_directionX;
}
void CPlayer::SetDirectionX(double cX)
{
	m_directionX = cX;
}

double CPlayer::GetDirectionZ()
{
	return m_directionZ;
}
void CPlayer::SetDirectionZ(double cZ)
{
	m_directionZ = cZ;
}

double CPlayer::GetAngle()
{
	return m_angle;
}
void CPlayer::SetAngle(double angle)
{
	m_angle = angle;
}

double CPlayer::GetSpeed()
{
	return m_speed;
}