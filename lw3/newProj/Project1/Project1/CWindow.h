#pragma once
#include "CBaseWindow.cpp"

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;

private:
	void OnRunStart() override;

	static void DrawEllipse(float cx, float cy, float rx, float ry);
	static void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	static void DrawCircle(float cx, float cy, float r);
	static void DrawRectangle(float cx, float cy, float height, float width);
	static void DrawBody();
	static void DrawConnectingRod();
	static void DrawCylinder();
	static void DrawShaft();
	static void DrawValves();
	static void DrawSparkPlug();
	static void DrawEngine();
	void Draw(int width, int height);
	static void SetupProjectionMatrix(int width, int height);
	static void SetupModelViewMatrix(double phase);
	static void Move();

	std::chrono::steady_clock::time_point m_startTime;
	const std::chrono::milliseconds ANIMATION_PERIOD = std::chrono::milliseconds{ 8000 };
};