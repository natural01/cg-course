#include "Vector3.h"
#include "CProgram.cpp"
#include <boost/noncopyable.hpp>
#include "CVertexBuffer.h"
#include "CSphere.h"
#include "CVertices.h"
#include <vector>
#include <memory>

struct Vertex
{
	CVector3f startPos;
	CVector3f endPos;
};

class CMorphShape : public boost::noncopyable
{
public:
	CMorphShape(size_t numberOfVertices);

	// �������� ������ � ��������� � ������������ �� ����������
	void SetProgram(
		GLuint program, GLuint phaseLocation, GLuint endPosLocation);

	// ������ ����
	void Draw(float phase)const;
private:
	// ������������� ������
	void Create()const;
	float GeneratePosZ(float stackAngle) const;
	float GenerateNextPosZ(float stackAngle, float stackStep) const;

	// ���������� ������ � ������
	size_t const m_numberOfVertices;

	// ��������� ����� � ��������� �� ����������� � ��� �������
	mutable bool m_initialized;
	mutable CVertexBuffer m_vertexBuffer;
	mutable GLubyte const* m_pStartPosArray;
	mutable GLubyte const* m_pEndPosArray;

	CProgramHandle m_program;
	GLuint m_phaseLocation;
	GLuint m_endPosLocation;

	std::vector<std::unique_ptr<CVertices>> m_startPosition;
};
