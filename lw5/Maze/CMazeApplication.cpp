#include "CMazeApplication.h"
#include <iostream>

const double CMazeApplication::Z_NEAR = 0.01;
const double CMazeApplication::Z_FAR = 40;

const float CMazeApplication::MAZE_SIZE = 32;

#define M_PI 3.141592653589793

const double CMazeApplication::FIELD_OF_VIEW = 60 * M_PI / 180.0;

CMazeApplication::CMazeApplication(const char* title, int width, int height, std::string mazeStructureFileName)
	: CGLApplication(title, width, height)
	, m_player(CPlayer())
	, m_map(CMap(mazeStructureFileName))
{
	LoadTexture(L"wall1.jpg", 0);
	LoadTexture(L"wall2.jpg", 1);
	LoadTexture(L"wall1.jpg", 2);
	LoadTexture(L"wall2.jpg", 3);
}

CMazeApplication::~CMazeApplication(void)
{
}

void CMazeApplication::OnInit()
{
	glLineWidth(2);
	glClearColor(1, 1, 1, 1);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);
}

void CMazeApplication::Walk()
{
	MoveRightLeft();
	MoveFrontBack();
}

void CMazeApplication::OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	const auto lookAtMat = glm::lookAt(
		glm::dvec3(m_player.GetCoordX(), m_player.GetCoordY(), m_player.GetCoordZ()),
		glm::dvec3(m_player.GetCoordX() + m_player.GetDirectionX(), m_player.GetCoordY(), m_player.GetCoordZ() + m_player.GetDirectionZ()),
		glm::dvec3(0, 1, 0)
	);
	glLoadMatrixd(&lookAtMat[0][0]);

	m_map.DrawWalls();
	Walk();
}

void CMazeApplication::OnReshape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, width, height);

	double aspectRatio = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const auto perspectiveMatrix = glm::perspective(FIELD_OF_VIEW, aspectRatio, Z_NEAR, Z_FAR);
	glLoadMatrixd(&perspectiveMatrix[0][0]);
	glMatrixMode(GL_MODELVIEW);
}

void CMazeApplication::MoveFrontBack()
{

	if (m_front)
	{
		if (m_player.GetDirectionZ() <= 0 && m_player.GetDirectionX() >= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() + m_player.GetDirectionZ() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() + m_player.GetDirectionX() * m_player.GetSpeed() + Z_NEAR * 2) / 2);
		}
		else if (m_player.GetDirectionZ() >= 0 && m_player.GetDirectionX() >= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() + m_player.GetDirectionZ() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() + m_player.GetDirectionX() * m_player.GetSpeed() + Z_NEAR * 2) / 2);
		}
		else if (m_player.GetDirectionZ() >= 0 && m_player.GetDirectionX() <= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() + m_player.GetDirectionZ() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() + m_player.GetDirectionX() * m_player.GetSpeed() - Z_NEAR * 2) / 2);
		}
		else if (m_player.GetDirectionZ() <= 0 && m_player.GetDirectionX() <= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() + m_player.GetDirectionZ() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() + m_player.GetDirectionX() * m_player.GetSpeed() - Z_NEAR * 2) / 2);
		}

		if (m_map.CheckWall(m_frontBorderZ, m_frontBorderX))
		{
			return;
		}
		m_player.SetCoordZ(m_player.GetCoordZ() + m_player.GetDirectionZ() * m_player.GetSpeed());
		m_player.SetCoordX(m_player.GetCoordX() + m_player.GetDirectionX() * m_player.GetSpeed());
	}
	if (m_back)
	{
		if (m_player.GetDirectionZ() <= 0 && m_player.GetDirectionX() >= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() - m_player.GetDirectionZ() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() - m_player.GetDirectionX() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
		}
		else if (m_player.GetDirectionZ() >= 0 && m_player.GetDirectionX() >= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() - m_player.GetDirectionZ() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() - m_player.GetDirectionX() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
		}
		else if (m_player.GetDirectionZ() >= 0 && m_player.GetDirectionX() <= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() - m_player.GetDirectionZ() * m_player.GetSpeed() - Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() - m_player.GetDirectionX() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
		}
		else if (m_player.GetDirectionZ() <= 0 && m_player.GetDirectionX() <= 0)
		{
			m_frontBorderZ = floor((m_player.GetCoordZ() - m_player.GetDirectionZ() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
			m_frontBorderX = floor((m_player.GetCoordX() - m_player.GetDirectionX() * m_player.GetSpeed() + Z_NEAR * 6) / 2);
		}

		if (m_map.CheckWall(m_frontBorderZ, m_frontBorderX))
		{
			return;
		}
		m_player.SetCoordZ(m_player.GetCoordZ() - m_player.GetDirectionZ() * m_player.GetSpeed());
		m_player.SetCoordX(m_player.GetCoordX() - m_player.GetDirectionX() * m_player.GetSpeed());
	}
}
void CMazeApplication::MoveRightLeft()
{
	if (m_left)
	{
		m_player.SetAngle(m_player.GetAngle() - 0.01f);
		m_player.SetDirectionX(sin(m_player.GetAngle()));
		m_player.SetDirectionZ(-cos(m_player.GetAngle()));
	}
	if (m_right)
	{
		m_player.SetAngle(m_player.GetAngle() + 0.01f);
		m_player.SetDirectionX(sin(m_player.GetAngle()));
		m_player.SetDirectionZ(-cos(m_player.GetAngle()));
	}
}

void CMazeApplication::OnKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		if (!m_back)
			m_front = !m_front;
		break;
	case 's':
		if (!m_front)
			m_back = !m_back;
		break;
	case 'a':
		if (!m_right)
			m_left = !m_left;
		break;
	case 'd':
		if (!m_left)
			m_right = !m_right;
		break;
	}
}
void CMazeApplication::UpKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		m_front = false;
		break;
	case 's':
		m_back = false;
		break;
	case 'a':
		m_left = false;
		break;
	case 'd':
		m_right = false;
		break;
	}
}

void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 10, Timer, 0);
}
void CMazeApplication::OnIdle()
{
	Timer(0);
}


GLuint CMazeApplication::LoadTexture(std::wstring const& fileName, GLuint const& texNum) // пеердавать по значени. texNum
{
	// Загружаем изображение при помощи GDI+
	Gdiplus::Bitmap bmp(fileName.c_str());

	if (bmp.GetLastStatus() != Gdiplus::Ok)
	{
		throw std::runtime_error("Error loading texture file");
	}

	// Определяем формат пикселей для использования 
	// с методом Bitmap::Lock и функцией gluBuild2DMipmaps
	Gdiplus::PixelFormat pixelFormat = 0;
	GLint textureFormat = 0;
	GLint colorComponents = 0;
	GLint internalFormat = 0;

	// Есть ли в изображении альфа-канал?
	if ((bmp.GetPixelFormat() & PixelFormatAlpha) != 0)
	{
		colorComponents = 4;
		pixelFormat = PixelFormat32bppARGB;
		textureFormat = GL_BGRA_EXT;
		internalFormat = GL_RGBA;
	}
	else
	{
		colorComponents = 3;
		textureFormat = GL_BGR_EXT;
		pixelFormat = PixelFormat24bppRGB;
		internalFormat = GL_RGB;
	}

	// Размеры и положение прямоугольной области изображения, 
	// доступ к данным которой мы хотим получить
	Gdiplus::Rect lockRect(0, 0, bmp.GetWidth(), bmp.GetHeight());

	// Получаем прямой доступ для чтения к данным растрового изображения
	Gdiplus::BitmapData bitmapData;
	bmp.LockBits(&lockRect, Gdiplus::ImageLockModeRead,
		pixelFormat, &bitmapData);
	//GLuint textureName = texNum;
	//// генерируем один уникальный идентификатор текстурного объекта
	//glGenTextures(1, &textureName);

	// делаем активным текстурный объект с данным идентификатором
	// (с ним еще пока не связано никакое изображение)
	glBindTexture(GL_TEXTURE_2D, texNum);

	// Задаем текстурное изображение для 0 уровня детализации
	glTexImage2D(
		GL_TEXTURE_2D,
		0,		// уровень детализации
		internalFormat,
		bitmapData.Width,
		bitmapData.Height,
		0,	// ширина рамки текстуры (0 - нет рамки, 1 - рамка в 1 пиксель)
		textureFormat,
		GL_UNSIGNED_BYTE,	// каждая компонента цвета занимает один байт
		bitmapData.Scan0	// адрес первой строки изображения
	);
	// Задаем параметры фильтрации текстуры при уменьшении и при увеличении
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Завершаем работу с данными растра
	bmp.UnlockBits(&bitmapData);

	// Возвращаем идентификатор созданного изображения
	return 0;
}