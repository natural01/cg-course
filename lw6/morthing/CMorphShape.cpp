#include "CMorphShape.h"

#define M_PI       3.14159265358979323846

CMorphShape::CMorphShape(size_t numberOfVertices)
	:m_pStartPosArray(NULL)
	, m_pEndPosArray(NULL)
	, m_numberOfVertices(numberOfVertices)
	, m_initialized(false)
{
}

void CMorphShape::SetProgram(
	GLuint program,
	GLuint phaseLocation,
	GLuint endPosLocation)
{
	m_program = program;
	m_phaseLocation = phaseLocation;
	m_endPosLocation = endPosLocation;
}

void CMorphShape::Draw(float phase)const
{
	if (!m_program)
	{
		throw std::logic_error("Shader program was not specified");
	}

	if (!m_initialized)
	{
		Create();
	}

	// ���������� ��������� ���������
	glUseProgram(m_program);

	// �������������� uniform-����������
	glUniform1f(m_phaseLocation, phase);

	// ��������� �������� ���������� ������
	m_vertexBuffer.Bind();

	// �������������� ������ �������� ������
	glVertexPointer(
		3, GL_FLOAT, sizeof(Vertex), m_pStartPosArray);
	glVertexAttribPointer(
		m_endPosLocation, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertex), m_pEndPosArray);

	// ��������� ������������� �������� ������ � ���������
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableVertexAttribArray(m_endPosLocation);

	// ������ ������
	glDrawArrays(GL_LINE_LOOP, 0, m_numberOfVertices);

	// ��������� ������������� �������� ������ � ���������
	glDisableVertexAttribArray(m_endPosLocation);
	glDisableClientState(GL_VERTEX_ARRAY);

	// ��������� ���������
	glUseProgram(0);
}

float CMorphShape::GeneratePosZ(float stackAngle) const
{
	if (sinf(stackAngle) > 0.75) { return 0.5 + 0.5 - (sinf(stackAngle) - 0.5); }
	else if (sinf(stackAngle) < 0.25) { return 0.5 - sinf(stackAngle); }
	else { return sinf(stackAngle); }
}
float CMorphShape::GenerateNextPosZ(float stackAngle, float stackStep) const
{
	if (sinf(stackAngle) > 0.75 || sinf(stackAngle) < 0.25) { return sinf(stackAngle + stackStep); }
	else { return sinf(stackAngle - stackStep); }
}

void CMorphShape::Create()const
{
	int count = 0;
	std::vector<Vertex> vertices(m_numberOfVertices);
	Vertex& v = vertices[count];
	// ��� �� ����������
	const float stackStep = M_PI / 20;
	// ��� �� ����������
	const float sliceStep = 2 * M_PI / 40;
	// ��������� ���� �� ����������
	for (unsigned stack = 0; stack < 20; ++stack)
	{
		float stackAngle = M_PI * 0.5 - stack * stackStep;
		float nextStackAngle = stackAngle - stackStep;

		const float stackRadius = cosf(stackAngle);
		const float nextStackRadius = cosf(nextStackAngle);
		const float z0 = sinf(stackAngle);
		const float z1 = sinf(nextStackAngle);

		glBegin(GL_TRIANGLE_STRIP);
		// ���� �� ����������
		for (unsigned slice = 0; slice <= 40; ++slice)
		{
			v = vertices[count];
			// ��������� ����, �������� ���������
			float sliceAngle = (slice != 40) ? slice * sliceStep : 0;

			// ��������� ���������� �� ������� ���������
			float x0 = stackRadius * cosf(sliceAngle);
			float y0 = stackRadius * sinf(sliceAngle);
			v.startPos = CVector3f(x0, y0, z0);
			v.endPos = CVector3f(x0, y0, GeneratePosZ(stackAngle));
			v = vertices[count+1];

			float x1 = nextStackRadius * cosf(sliceAngle);
			float y1 = nextStackRadius * sinf(sliceAngle);
			v.startPos = CVector3f(x1, y1, z1);
			v.endPos = CVector3f(x1, y1, GenerateNextPosZ(stackAngle, stackStep));
			count = count + 2;
		}
		glEnd();
	}

	// ������� � ��������� ������� ����� ������
	m_vertexBuffer.Create();
	m_vertexBuffer.BufferData(
		sizeof(Vertex) * m_numberOfVertices,
		&vertices[0],
		GL_STATIC_DRAW
	);

	// ���������� ������ �������� ��������� � �������� ��������� ������
	const GLubyte* pBufferPointer =
		static_cast<const GLubyte*>(m_vertexBuffer.GetBufferPointer());

	m_pStartPosArray = pBufferPointer + offsetof(Vertex, startPos);
	m_pEndPosArray = pBufferPointer + offsetof(Vertex, endPos);

	// ��������, ��� ������ ��� ������������������
	m_initialized = true;
}
