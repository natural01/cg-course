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

	// ������������� ����������� ������, ������������ ��������� �����
	mutable GLuint m_displayList;
	float m_radius; // ������
	unsigned m_slices; // ���������� ����������
	unsigned m_stacks; // ���������� ����������
};
