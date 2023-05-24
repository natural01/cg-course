#include <iostream>
#include "CMazeApplication.h"
#include "CGdiplusInitializer.cpp"

CGdiplusInitializer gdiplusInitializer;
CMazeApplication maze("Maze", 1200, 750, "maze.txt");

int main()
{
    maze.MainLoop();
}