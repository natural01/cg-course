#include "CGLApplication.h"
#include "CMap.h"
#include "CPlayer.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include <math.h>

#pragma once
class CMazeApplication : public CGLApplication
{
public:
	CMazeApplication(const char* title, int width, int height, std::string mazeStructureFileName);
	~CMazeApplication(void);
protected:
	virtual void OnInit();
	virtual void OnDisplay();
	virtual void OnReshape(int width, int height);
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void UpKeyboard(unsigned char key, int x, int y);
	void MoveFrontBack();
	void MoveRightLeft();
	virtual void OnIdle();
private:
	static const double Z_NEAR;
	static const double Z_FAR;

	static const double FIELD_OF_VIEW;
	static const float MAZE_SIZE;

	CPlayer m_player;

	CMap m_map;
	static GLuint LoadTexture(std::wstring const& fileName, GLuint const& texNum);
	bool m_front = false;
	bool m_back = false;
	bool m_left = false;
	bool m_right = false;
	int m_frontBorderX = 0;
	int m_frontBorderZ = 0;
	void Walk();
};