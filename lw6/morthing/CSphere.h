#include "GL/glut.h"

#pragma once
class CSphere
{
public:
	CSphere(float radius, unsigned slices, unsigned stacks);
	~CSphere();

	void Draw() const;

private:
	void DrawSphere() const;

	// »дентификатор дисплейного списка, выполн€ющего рисование сферы
	mutable GLuint m_displayList;
	float m_radius; // радиус
	unsigned m_slices; // количество меридианов
	unsigned m_stacks; // количество параллелей
};
