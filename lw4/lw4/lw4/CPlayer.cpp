#include "CPlayer.h"
#include "glut.h"

CPlayer* CPlayer::m_player = NULL;

CPlayer::CPlayer(GLFWwindow* window)
	: m_window(window)
{
	if (m_player)
	{
		throw("Only one instance of the application is permitted");
		return;
	}
	m_player = this;
	SetKeyCallback();
}

void CPlayer::GoFront()
{
	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x + m_rotateX * 0.1, m_cameraPosition.GetPoint().y + m_rotateY * 0.1, m_cameraPosition.GetPoint().z);
}
void CPlayer::GoBack()
{
	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x - m_rotateX * 0.1, m_cameraPosition.GetPoint().y - m_rotateY * 0.1, m_cameraPosition.GetPoint().z);
}
void CPlayer::MoveLeft()
{
	m_carnerOfCamera = m_carnerOfCamera - 1.0;
	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x - sin(m_carnerOfCamera + 80.0) * 0.1, m_cameraPosition.GetPoint().y + cos(m_carnerOfCamera + 80.0) * 0.1, m_cameraPosition.GetPoint().z);
}
void CPlayer::MoveRight()
{
	m_carnerOfCamera = m_carnerOfCamera + 1.0;
	m_cameraPosition.SetPoint(m_cameraPosition.GetPoint().x + sin(m_carnerOfCamera + 80.0) * 0.1, m_cameraPosition.GetPoint().y - cos(m_carnerOfCamera + 80.0) * 0.1, m_cameraPosition.GetPoint().z);
}

double CPlayer::GetCarnerOfCamera()
{
	return m_carnerOfCamera;
}

void CPlayer::SetKeyCallback()
{
	glutKeyboardFunc(&KeyCallback);
}

CPoint* CPlayer::GetCameraPosition()
{
	return &m_cameraPosition;
}

CPoint* CPlayer::GetMainPosition()
{
	return &m_mainPosition;
}

CPoint* CPlayer::GetDirection()
{
	return &m_direction;
}

void CPlayer::KeyCallback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case GLFW_KEY_W:
		m_player->GoFront();
		break;
	case GLFW_KEY_A:
		m_player->MoveLeft();
		break;
	case GLFW_KEY_S:
		m_player->GoBack();
		break;
	case GLFW_KEY_D:
		m_player->MoveRight();
		break;
	}
}
