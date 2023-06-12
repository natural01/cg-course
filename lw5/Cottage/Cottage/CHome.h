#include "GL/glut.h"
#include "ÑRoof.h"
#include "CPorch.h"
#include <vector>
#include "CDoor.h"
#include <memory>
#include "CWindow.h"
#include "CGate.h"

#pragma once
class CHome
{
public:
	CHome(float x, float y, float height, float width, float lon);
	void DrawHome() const;
	void SetPorchPosition(float x, float y, int countOfPorch);

	void AddPorch();
	void AddDoor(float x1, float y1, float x2, float y2);
	void AddWindow(float x1, float y1, float x2, float y2);
	void AddGate(float x1, float y1, float x2, float y2);

private:
	float m_positionX;
	float m_positionY;
	float m_height;
	float m_width;
	float m_long;

	void DrawPorch() const;
	void DrawRoof() const;
	void DrawDoor() const;
	void DrawWindow() const;
	void DrawGates() const;

	std::vector<std::unique_ptr<CPorch>> m_porches;
	std::vector<std::unique_ptr<CDoor>> m_doors;
	std::vector<std::unique_ptr<CWindow>> m_windows;
	std::vector<std::unique_ptr<CGate>> m_gates;
};