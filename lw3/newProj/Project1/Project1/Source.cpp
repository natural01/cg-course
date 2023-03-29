#include <GLFW/glfw3.h>
#include <chrono>
#include <stdexcept>

class GLFWInitializer final
{
public:
	GLFWInitializer()
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize GLFW");
		}
	}

	GLFWInitializer(const GLFWInitializer&) = delete;
	GLFWInitializer& operator=(const GLFWInitializer&) = delete;

	~GLFWInitializer()
	{
		glfwTerminate();
	}
};

class BaseWindow
{
public:
	BaseWindow(int w, int h, const char* title)
		: m_window{ CreateWindow(w, h, title) }
	{
		if (!m_window)
		{
			throw std::runtime_error("Failed to create window");
		}
	}
	BaseWindow(const BaseWindow&) = delete;
	BaseWindow& operator=(const BaseWindow&) = delete;

	virtual ~BaseWindow()
	{
		glfwDestroyWindow(m_window);
	}

	void Run()
	{
		glfwMakeContextCurrent(m_window);
		//OnRunStart();
		while (!glfwWindowShouldClose(m_window))
		{
			int w, h;
			glfwGetFramebufferSize(m_window, &w, &h);
			Draw(w, h);
			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
		OnRunEnd();
	}

private:
	virtual void Draw(int width, int height) = 0;

	//virtual void OnRunStart() {}
	virtual void OnRunEnd() {}

	static GLFWwindow* CreateWindow(int w, int h, const char* title)
	{
		return glfwCreateWindow(w, h, title, nullptr, nullptr);
	}
	GLFWwindow* m_window;
};

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;

private:
	/*void OnRunStart() override
	{
		m_startTime = std::chrono::steady_clock::now();
	}*/

	void DrawEllipse(float cx, float cy, float rx, float ry)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 300; i++) {
			double angle = 2 * 3.1415926f * i / 300;
			double x = cos(angle) * rx;
			double y = sin(angle) * ry;
			glVertex2d(cx + x, cy + y);
		}
		glEnd();
	}

	void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) 
	{
		glBegin(GL_TRIANGLES);
			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);
		glEnd();
	}
	void DrawCircle(float cx, float cy, float r) {
		glBegin(GL_POLYGON);
			for (int i = 0; i <= 300; i++) {
				double angle = 2 * 3.1415926f * i / 300;
				double x = cos(angle) * r;
				double y = sin(angle) * r;
				glVertex2d(cx + x, cy + y);
			}
		glEnd();
	}
	void DrawRectangle(float cx, float cy, float height, float width)
	{
		glBegin(GL_QUADS);
			glVertex3f(cx, cy, 0.0);
			glVertex3f(cx + width, cy, 0.0);
			glVertex3f(cx + width, cy - height, 0.0);
			glVertex3f(cx, cy - height, 0.0);
		glEnd();
	}

	void Draw(int width, int height) override
	{
		using namespace std::chrono;
		/*const auto currentTime = steady_clock::now();
		const auto timeSinceStart = currentTime - m_startTime;
		const auto phase = duration_cast<duration<double>>(timeSinceStart % ANIMATION_PERIOD) / ANIMATION_PERIOD;*/

		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, width, height);
		//SetupProjectionMatrix(width, height);

		// шатун
		glColor3f(0.539, 0.545, 0.549);
		DrawRectangle(-0.27, 0.7, 1.0, 0.57);

		glColor3f(0.228, 0.235, 0.242);
		DrawTriangle(0.0, 0.22, -0.1, -0.5, 0.1, -0.5);
		glColor3f(0.0, 0.0, 0.0);
		DrawRectangle(-0.01, 0.2, 0.6, 0.02);
		glColor3f(0.170, 0.169, 0.173);
		DrawRectangle(-0.12, -0.4, 0.1, 0.24);

		// клапан

		glColor3f(0.170, 0.169, 0.173);
		DrawRectangle(-0.25, 0.65, 0.6, 0.5);
		DrawRectangle(-0.27, 0.65, 0.02, 0.54);

		glColor3f(0.0, 0.0, 0.0);
		DrawRectangle(-0.27, 0.6, 0.02, 0.54);
		DrawRectangle(-0.27, 0.56, 0.02, 0.54);
		DrawRectangle(-0.27, 0.52, 0.02, 0.54);
		DrawCircle(0.0, 0.22, 0.1);

		// стенки
		glColor3f(0.124, 0.192, 0.244);
		DrawRectangle(-0.4, 0.7, 0.035, 0.13);
		DrawRectangle(-0.3, 0.7, 1.0, 0.035);
		DrawRectangle(0.27, 0.7, 0.035, 0.13);
		DrawRectangle(0.27, 0.7, 1.0, 0.035);

		// вал
		glColor3f(0.195, 0.209, 0.219);
		DrawCircle(0.0, -0.5, 0.08);
		DrawEllipse(0.0, -0.65, 0.1, 0.17);
		DrawEllipse(0.0, -0.83, 0.2, 0.07);
		glColor3f(0.0, 0.0, 0.0);
		DrawCircle(0.0, -0.65, 0.05);

		glColor3f(0.539, 0.545, 0.549);
		DrawRectangle(-0.4, 0.8, 0.1, 0.8);
		glColor3f(0.184, 0.231, 0.255);
		DrawRectangle(-0.4, 0.72, 0.02, 0.17);
		DrawRectangle(0.23, 0.72, 0.02, 0.17);
		DrawRectangle(-0.1, 0.82, 0.12, 0.05);
		DrawRectangle(0.05, 0.82, 0.12, 0.05);
		DrawRectangle(-0.3, 1.0, 0.18, 0.6);
		DrawRectangle(-0.4, 0.82, 0.05, 0.8);
		glColor3f(0.539, 0.545, 0.549);
		DrawRectangle(-0.25, 1.0, 0.2, 0.15);
		DrawRectangle(0.1, 1.0, 0.2, 0.15);
		glColor3f(1.0, 1.0, 1.0);
		DrawRectangle(-0.05, 1.0, 0.2, 0.1);

		// клапаны
		glColor3f(0.255, 0.221, 0.49);
		DrawRectangle(-0.18, 1.5, 0.8, 0.03);
		DrawRectangle(0.15, 1.5, 0.8, 0.03);
		DrawTriangle(-0.165, 0.75, -0.23, 0.7, -0.1, 0.7);
		DrawTriangle(0.165, 0.75, 0.23, 0.7, 0.1, 0.7);

		// свеча
		glColor3f(0.0, 0.0, 0.0);
		DrawRectangle(-0.03, 0.8, 0.1, 0.06);
		glColor3f(0.295, 0.309, 0.319);
		DrawRectangle(-0.03, 0.83, 0.03, 0.06);
		glColor3f(0.228, 0.235, 0.242);
		DrawRectangle(-0.04, 0.85, 0.02, 0.08);
		DrawRectangle(-0.04, 0.85, 0.05, 0.02);
		DrawRectangle(0.02, 0.85, 0.05, 0.02);
		glColor3f(0.628, 0.635, 0.642);
		DrawRectangle(-0.02, 0.9, 0.05, 0.04);
		glColor3f(0.628, 0.635, 0.642);
		DrawRectangle(-0.01, 0.95, 0.05, 0.02);

		glFlush();
	}

	/*static void SetupProjectionMatrix(int width, int height)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		const double aspectRatio = double(width) / double(height);
		double viewWidth = 2.0;
		double viewHeight = viewWidth;
		if (aspectRatio > 1.0)
		{
			viewWidth = viewHeight * aspectRatio;
		}
		else
		{
			viewHeight = viewWidth / aspectRatio;
		}
		glOrtho(-viewWidth * 0.5, viewWidth * 0.5, -viewHeight * 0.5, viewHeight * 0.5, -1.0, 1.0);
	}

	static void SetupModelViewMatrix(double phase)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(0.0, phase * 0.2, 0.0);
	}*/

	/*std::chrono::steady_clock::time_point m_startTime;
	const std::chrono::milliseconds ANIMATION_PERIOD = std::chrono::milliseconds{ 8000 };*/
};

int main()
{
	GLFWInitializer initGLFW;
	Window window{ 1000, 1000, "Hello, triangle" };
	window.Run();
}