#define GLEW_STATIC
#include "glew.h"
#include "CMorphApplication.h"
#include "CShaderLoader.h"
#include "CShaderCompiler.h"
#include "CProgramLinker.h"

#define M_PI       3.14159265358979323846
// Угол обзора по вертикали
const double CMorphApplication::FIELD_OF_VIEW = 60;
// Расстояине до ближней плоскости отсчечения камеры
const double CMorphApplication::ZNEAR = 1;
// Расстояине до дальней плоскости отсчечения камеры
const double CMorphApplication::ZFAR = 10;
const float CMorphApplication::ROTATION_SPEED = 20;

const int CMorphApplication::NUMBER_OF_VERTICES = 800;
const float CMorphApplication::ANIMATION_PERIOD = 2.0f;

CMorphApplication::CMorphApplication (const char* title, int width, int height, GLuint program)
	: CGLApplication(title, width, height)
	, m_program(program)
	, m_sphere(1, 40, 20)
{
}

CMorphApplication::~CMorphApplication ()
{
	if (m_program)
	{
		glDeleteProgram(m_program);
	}

}

void CMorphApplication::SetupCamera()
{
	DWORD currentTick = GetTickCount();

	float delta = (currentTick - m_lastTick) * 0.001;
	m_lastTick = currentTick;

	// вычисляем угол поворота камеры
	m_rotationAngle = fmodf(m_rotationAngle + ROTATION_SPEED * delta, 360);

	// Устанавливаем камеру
	glLoadIdentity();
	gluLookAt(
		2, 3, 2, // Положение глаза наблюдателя
		0, 0, 0, 	// Точка, в которую направлена камера
		0, 0, 1	// Вектор, служащий для определения вектора "вверх"
	);

	// Вращаем камеру вокруг оси Z
	glRotatef(m_rotationAngle, 0, 0, 1);
}

void CMorphApplication::InitShaders()
{
	// Загружаем шейдеры
	CShaderLoader loader;
	CShader vertexShader =
		loader.LoadShader(GL_VERTEX_SHADER, L"shaders/vertex_shader.vert");

	// Создаем программы и присоединяем к ней шейдеры
	m_program.Create();
	m_program.AttachShader(vertexShader);

	// Компилируем шейдеры
	CShaderCompiler compiler;
	compiler.CompileShader(vertexShader);
	compiler.CheckStatus();

	// Компонуем программу
	CProgramLinker linker;
	linker.LinkProgram(m_program);
	linker.CheckStatus();
}

void CMorphApplication::OnInit()
{
	m_lastTick = GetTickCount();
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1);
	glColor3f(0, 0, 0);

	InitShaders();

	//// Получаем расположение uniform и attribute-переменных
	//GLint phaseLocation = m_program.GetUniformLocation("phase");
	//GLint vertex2Location = m_program.GetAttribLocation("endPosition");;
	//// Передаем информацию о программе и ее переменных фигуре
	//m_morphShape.SetProgram(m_program, phaseLocation, vertex2Location);
}

void CMorphApplication ::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);

	// Вычисляем соотношение сторон клиентской области окна
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FIELD_OF_VIEW, aspect, ZNEAR, ZFAR);
	glMatrixMode(GL_MODELVIEW);

}

void CMorphApplication::OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupCamera();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//m_morphShape.Draw((sinf(m_phase) + 1) / 2);
	m_sphere.Draw();

	//glUseProgram(m_program);

	/*glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);
		glVertex2f(-0.8, -0.8);

		glTexCoord2f(4, 0);
		glVertex2f(0.8, -0.8);

		glTexCoord2f(4, 4);
		glVertex2f(0.8, 0.8);

		glTexCoord2f(0, 4);
		glVertex2f(-0.8, 0.8);
	}
	glEnd();*/

	//glUseProgram(0);
}

void CMorphApplication::OnIdle()
{
	/*m_animationController.Tick();

	float delta = m_animationController.GetTimeDelta() * 0.001f;

	m_phase = fmodf(
		float(m_phase + delta * 2 * M_PI / ANIMATION_PERIOD),
		float(2 * M_PI)
	);*/

	PostRedisplay();
}