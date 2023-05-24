#include "CGLApplication.h"
#include "CMap.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <math.h>

#pragma once
class CCottageApplication : public CGLApplication
{
public:
	CCottageApplication(const char* title, int width, int height);
	~CCottageApplication(void);
protected:
	virtual void OnInit();
	virtual void OnDisplay();
	virtual void OnReshape(int width, int height);
	virtual void OnIdle();
private:
	static const double FIELD_OF_VIEW;
	static const double ZNEAR;
	static const double ZFAR;
	void SetupCamera();
	static const float ROTATION_SPEED;
	float m_rotationAngle;
	DWORD m_lastTick;

	CMap m_map;
	static GLuint LoadTexture(std::wstring const& fileName, GLuint const& texNum);
};