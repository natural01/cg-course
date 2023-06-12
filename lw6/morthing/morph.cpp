#include <iostream>
#include "CMorphApplication.h"

CMorphApplication  arrow("flag", 1300, 750);

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