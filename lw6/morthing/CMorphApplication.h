#pragma once
#include <iostream>
#include "CGLApplication.h"
#include "CProgram.cpp"
#include "CShader.cpp"
#include "CSphere.h"
#include <windows.h>

class CMorphApplication : public CGLApplication
{
public:
	CMorphApplication(const char* title, int width, int height, GLuint program = 0);
    ~CMorphApplication ();
protected:
	virtual void OnInit();
	virtual void OnDisplay();
	virtual void OnReshape(int width, int height);
	virtual void OnIdle();
private:
	void SetupCamera();
	void InitShaders();

	static const double FIELD_OF_VIEW;
	static const double ZNEAR;
	static const double ZFAR;
	static const float ROTATION_SPEED;

	// Количество вершин в фигуре
	static const int NUMBER_OF_VERTICES;
	// Период полной анимации морфинга
	static const float ANIMATION_PERIOD;

	CProgram m_program;

	//CMorphShape m_morphShape;
	//float m_phase;
	CSphere m_sphere;
	//CAnimationController m_animationController;

	float m_rotationAngle;
	DWORD m_lastTick;
};