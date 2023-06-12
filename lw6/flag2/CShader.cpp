#pragma once
#include <iostream>
#include <vector>
#define GLEW_STATIC
#include "glew.h"
#include "GL/glut.h"
#include <assert.h>

//������� ����� ��� ������ � ��������� �������� OpenGL

class CShaderBase
{
	// ���������� ����������� � ���������� ������� 
	// ��������� ������������� ������� ������ ������ 
	// ��� ��� ��������
protected:
	CShaderBase(GLuint shader = 0)
		:m_shader(shader)
	{
	}

	// ��������� ���������� ����������, �.�. � ���������
	// ������ ���������� ������ �� ��� ���������
	// ��������� ���������� ����������� ��� �������������
	// �.�. ���������� ������� �� ������ �����, � ������
	// ������� CShaderBase �������� �� ��������� (������ ������
	// ��� ����������)
	~CShaderBase()
	{
		// ������ ���������� �� ������ ������
		// ������������� �������� ����� ���������� 
		// �����-�������
	}
public:
	// ������ �������� ��� �������
	void SetSource(GLsizei count, const char** strings, const GLint* lengths)
	{
		assert(m_shader != 0);

		glShaderSource(m_shader, count, strings, lengths);
	}

	// ������ �������� ��� ������� (� ����� ������)
	void SetSource(const char* source, GLint length)
	{
		const char** ppSource = &source;
		SetSource(1, ppSource, &length);
	}

	// ������ �������� ��� ������� (���� ASCIIZ-������)
	void SetSource(const char* source)
	{
		const char** ppSource = &source;
		SetSource(1, ppSource, NULL);
	}

	// �������� �������� ���������� ��������� �������
	void GetParameter(GLenum pname, GLint* param)const
	{
		assert(m_shader != 0);
		glGetShaderiv(m_shader, pname, param);
	}

	// ���������� ������� ����������� ������
	GLint GetParameter(GLenum pname)const
	{
		GLint value;
		GetParameter(pname, &value);
		return value;
	}

	// �������� �������������� ��� �� �������
	void GetInfoLog(GLsizei bufSize, GLsizei* length, char* infoLog)const
	{
		assert(m_shader != 0);
		glGetShaderInfoLog(m_shader, bufSize, length, infoLog);
	}

	// �������� �������������� ��� �� �������
	// (���������� �������)
	std::string GetInfoLog()const
	{
		GLint length = GetParameter(GL_INFO_LOG_LENGTH);
		if (length > 0)
		{
			std::vector<char> buffer(length);
			GetInfoLog(length, &length, &buffer[0]);
			std::string log(&buffer[0]);
			return log;
		}
		else
		{
			return std::string();
		}
	}

	// �������� ������������� ���������� �������
	operator GLuint()const
	{
		return m_shader;
	}

	// �������� ������������� ���������� ������� (�������������� �������)
	GLuint Get()const
	{
		return m_shader;
	}

	// ����������� ������
	void Compile()
	{
		assert(m_shader != 0);
		glCompileShader(m_shader);
	}

	// ������������ ��������� ������ � ������ � ����������
	// ���������� ����� ���������������
	GLuint Attach(GLuint shader)
	{
		GLuint tmp = m_shader;
		m_shader = shader;
		return tmp;
	}

	// ����������� ��������� ������
	GLuint Detach()
	{
		return Attach(0);
	}

	// ������� ��������� ������
	void Delete()
	{
		assert(m_shader != 0);
		if (m_shader != 0)
		{
			glDeleteShader(Detach());
			m_shader = 0;
		}
	}

private:
	// ������ ������������ ����������� �����������
	// � �������� ������������
	CShaderBase(CShaderBase const&);
	CShaderBase& operator=(CShaderBase const&);

	GLuint m_shader;
};

/*
��������� ���������� ������ "��������� ������ OpenGL"
�������� t_managed ����������, ����� �� ����� �����
���������� ������� ����������� ������� CShaderImpl ��� ���
*/
template <bool t_managed>
class CShaderImpl : public CShaderBase
{
public:
	CShaderImpl(GLuint shader = 0)
		:CShaderBase(shader)
	{
	}

	// �������� ������������ ��������� 
	CShaderImpl& operator=(GLuint shader)
	{
		// ������� ������� ��������� ������ ������ ����:
		if (
			t_managed &&		// ����� ��������� ��������� ��������
			(Get() != 0) &&		// ����� ������� ��������� ������
			(Get() != shader)	// � �� �� ��������� � ����������
			)
		{
			Delete();
		}
		Attach(shader);
		return *this;
	}

	// ������� ������ ��������� ����
	GLuint Create(GLenum type)
	{
		// ������� ������ ��������� ������ � ������ ������������� 
		// (���� �� ����� � ����� ��������� ��������)
		if ((Get() != 0) && t_managed)
		{
			Delete();
		}
		GLuint shader = glCreateShader(type);
		Attach(shader);
		return shader;
	}

	// ���������� ������ ������� ��������� ������ (���� ����� ���������
	// ��������� ��������)
	~CShaderImpl(void)
	{
		if (t_managed && (Get() != 0))
		{
			Delete();
		}
	}
};

// ��� "��������� ������"
// (� �������������� ����������� ������ ����� 
// ���������� ������� OpenGL)
typedef CShaderImpl<true > CShader;
// ��� "���������� ���������� �������" 
// (��� ��������������� ���������� ��������
// ����� ���������� ������� OpenGL)
typedef CShaderImpl<false> CShaderHandle;
