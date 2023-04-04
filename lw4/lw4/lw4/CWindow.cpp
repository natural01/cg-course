#include "CWindow.h"

void Window::OnRunStart()
{
	// Задаем цвет очистки буфера кадра
	glClearColor(1, 1, 0, 1);
}

void Window::Draw(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupProjectionMatrix(width, height);
	SetupCameraMatrix();
	glEnable(GL_DEPTH_TEST);

	CFrame frame;
	frame.Draw();

	// Рисуем красный квадрат в плоскости XOY
	glColor3f(1, 0, 0);
	glRectf(-1, -1, 1, 1);

	// Рисуем синий квадрат в плоскости Z=0, предварительно задав для него
	// трансформацию повоота вокруг оси Y и а затем переноса на 0.2 вдоль оси Z
	// Порядок умножения матриц - обратный
	glTranslatef(0, 0, 0.2f);
	glRotatef(60, 0, 1, 0);

	glColor3f(0, 0, 1);
	glRectf(-0.5, -1.0, +0.5, +0.5);
}

void Window::SetupProjectionMatrix(int width, int height)
{
	glViewport(0, 0, width, height);

	// Вычисляем соотношение сторон клиентской области окна
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	const auto projMat = glm::perspective(60.0 * M_PI / 180.0, aspect, 0.1, 10.0);
	glLoadMatrixd(&projMat[0][0]);
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	const auto lookAtMat = glm::lookAt(
		glm::dvec3(0, -4, 4), // Положение камеры
		glm::dvec3(0, 0, 0), // Точка, в которую направлена камера
		glm::dvec3(0, 1, 0) // Направление "вверх"
	);
	glLoadMatrixd(&lookAtMat[0][0]);
}