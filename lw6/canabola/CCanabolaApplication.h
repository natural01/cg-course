#pragma once
#include <iostream>
#include "CGLApplication.h"
#include "CProgram.h"
#include "CShader.cpp"

class CCanabolaApplication :
    public CGLApplication
{
public:
	CCanabolaApplication(const char* title, int width, int height, GLuint program = 0);
    ~CCanabolaApplication ();
protected:
	virtual void OnInit();
	virtual void OnDisplay();
	virtual void OnReshape(int width, int height);
private:
	void InitShaders();

	CProgram m_program;

	static const double FIELD_OF_VIEW;
	static const double ZNEAR;
	static const double ZFAR;
};