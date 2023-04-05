#include "CWindow.h"

void Window::OnRunStart()
{
	glClearColor(1, 1, 1, 1);
}

void Window::Draw(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupProjectionMatrix(width, height);
	SetupCameraMatrix();
	glEnable(GL_DEPTH_TEST);

	CFrame frame;
	frame.Draw();

	// ������ ������� ������� � ��������� XOY
	glColor3f(1, 0, 0);
	glRectf(-1, -1, 1, 1);

	// ������ ����� ������� � ��������� Z=0, �������������� ����� ��� ����
	// ������������� ������� ������ ��� Y � � ����� �������� �� 0.2 ����� ��� Z
	// ������� ��������� ������ - ��������
	glTranslatef(0, 0, 0.2f);
	glRotatef(60, 0, 1, 0);

	glColor3f(0, 0, 1);
	glRectf(-0.5, -1.0, +0.5, +0.5);
}

void Window::SetupProjectionMatrix(int width, int height)
{
	glViewport(0, 0, width, height);

	// ��������� ����������� ������ ���������� ������� ����
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	const auto projMat = glm::perspective(60.0 * M_PI / 180.0, aspect, 0.1, 10.0);
	glLoadMatrixd(&projMat[0][0]);
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	const auto lookAtMat = glm::lookAt(
		glm::dvec3(0, -4, 4), // ��������� ������
		glm::dvec3(0, 0, 0), // �����, � ������� ���������� ������
		glm::dvec3(0, 1, 0) // ����������� "�����"
	);
	glLoadMatrixd(&lookAtMat[0][0]);
}