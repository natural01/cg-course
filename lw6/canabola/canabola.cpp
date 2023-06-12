#include <iostream>
#include "CCanabolaApplication.h"

CCanabolaApplication  arrow("canabola", 1300, 750);

int main()
{
	glewInit();
	if (!GLEW_ARB_shader_objects)
	{
		return -1;
	}

	arrow.MainLoop();

	return 0;
}