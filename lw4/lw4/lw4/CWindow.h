#pragma once
#include "CBaseWindow.h"

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;

private:
	void OnRunStart() override;

	void Draw(int width, int height) override;

	static void SetupProjectionMatrix(int width, int height);

	static void SetupCameraMatrix();
};