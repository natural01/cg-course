#include "CCottageApplication.h"
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#define M_PI 3.141592653589793

const double CCottageApplication::FIELD_OF_VIEW = 60;
// ���������� �� ������� ��������� ��������� ������������� ������
const double CCottageApplication::ZNEAR = 0.5;
// ���������� �� ������ ��������� ��������� ������������� ������
const double CCottageApplication::ZFAR = 10;
const float CCottageApplication::ROTATION_SPEED = 20;


CCottageApplication::CCottageApplication(const char* title, int width, int height)
	: CGLApplication(title, width, height)
{
	LoadTexture(L"lawn.jpg", 0);
	LoadTexture(L"wall.jpg", 1);
	LoadTexture(L"roof.jpg", 2);
	LoadTexture(L"gable.jpg", 3);
	LoadTexture(L"fence.jpg", 4);
	LoadTexture(L"porch.jpg", 5);
	LoadTexture(L"door.jpg", 6);
	LoadTexture(L"window.jpg", 7);
	LoadTexture(L"gates.jpg", 8);

}

CCottageApplication::~CCottageApplication(void)
{
}

void CCottageApplication::SetupCamera()
{
	DWORD currentTick = GetTickCount();

	float delta = (currentTick - m_lastTick) * 0.001;
	m_lastTick = currentTick;

	// ��������� ���� �������� ������
	m_rotationAngle = fmodf(m_rotationAngle + ROTATION_SPEED * delta, 360);

	// ������������� ������
	glLoadIdentity();
	gluLookAt(
		2, 3, 2, // ��������� ����� �����������
		0, 0, 0, 	// �����, � ������� ���������� ������
		0, 0, 1	// ������, �������� ��� ����������� ������� "�����"
	);

	// ������� ������ ������ ��� Z
	glRotatef(m_rotationAngle, 0, 0, 1);
}


void CCottageApplication::OnInit()
{
	m_lastTick = GetTickCount();
	glLineWidth(2);
	glClearColor(1, 1, 1, 1);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);
}

void CCottageApplication::OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glNormal3f(0, 0, 1);

	SetupCamera();

	m_map.DrawMap();
}

void CCottageApplication::OnReshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double aspect = double(width) / double(height);
	gluPerspective(FIELD_OF_VIEW, aspect, ZNEAR, ZFAR);
	glMatrixMode(GL_MODELVIEW);
}

void CCottageApplication::OnIdle()
{
	PostRedisplay();
}


GLuint CCottageApplication::LoadTexture(std::wstring const& fileName, GLuint const& texNum) // ���������� �� �������. texNum
{
	// ��������� ����������� ��� ������ GDI+
	Gdiplus::Bitmap bmp(fileName.c_str());

	if (bmp.GetLastStatus() != Gdiplus::Ok)
	{
		throw std::runtime_error("Error loading texture file");
	}

	// ���������� ������ �������� ��� ������������� 
	// � ������� Bitmap::Lock � �������� gluBuild2DMipmaps
	Gdiplus::PixelFormat pixelFormat = 0;
	GLint textureFormat = 0;
	GLint colorComponents = 0;
	GLint internalFormat = 0;

	// ���� �� � ����������� �����-�����?
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

	// ������� � ��������� ������������� ������� �����������, 
	// ������ � ������ ������� �� ����� ��������
	Gdiplus::Rect lockRect(0, 0, bmp.GetWidth(), bmp.GetHeight());

	// �������� ������ ������ ��� ������ � ������ ���������� �����������
	Gdiplus::BitmapData bitmapData;
	bmp.LockBits(&lockRect, Gdiplus::ImageLockModeRead,
		pixelFormat, &bitmapData);
	//GLuint textureName = texNum;
	//// ���������� ���� ���������� ������������� ����������� �������
	//glGenTextures(1, &textureName);

	// ������ �������� ���������� ������ � ������ ���������������
	// (� ��� ��� ���� �� ������� ������� �����������)
	glBindTexture(GL_TEXTURE_2D, texNum);

	// ������ ���������� ����������� ��� 0 ������ �����������
	glTexImage2D(
		GL_TEXTURE_2D,
		0,		// ������� �����������
		internalFormat,
		bitmapData.Width,
		bitmapData.Height,
		0,	// ������ ����� �������� (0 - ��� �����, 1 - ����� � 1 �������)
		textureFormat,
		GL_UNSIGNED_BYTE,	// ������ ���������� ����� �������� ���� ����
		bitmapData.Scan0	// ����� ������ ������ �����������
	);
	// ������ ��������� ���������� �������� ��� ���������� � ��� ����������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// ��������� ������ � ������� ������
	bmp.UnlockBits(&bitmapData);

	// ���������� ������������� ���������� �����������
	return 0;
}