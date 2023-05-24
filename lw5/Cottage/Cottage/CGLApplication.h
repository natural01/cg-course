#include <math.h>
#include "GL/glut.h"
#include <windows.h>

#pragma once
class CGLApplication
{
public:
	void MainLoop();
protected:
	CGLApplication(
		const char* title,
		int width = 0,
		int height = 0,
		bool needDepth = true,
		bool needStencil = false
	);
	virtual ~CGLApplication();

	virtual void OnInit();
	virtual void OnDisplay() = 0;
	virtual void OnReshape(int width, int height);
	virtual void OnMotion(int x, int y);
	virtual void OnIdle();

	void PostRedisplay();

private:
	void InitEventHandlers();
	static void DisplayHandler();
	static void ReshapeHandler(int width, int height);
	static void MotionHandler(int x, int y);
	static void IdleHandler();
	static CGLApplication* m_pApplication;
};