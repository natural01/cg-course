#include <iostream>
#include "CGdiplusInitializer.cpp"
#include "CCottageApplication.h"

CGdiplusInitializer gdiplusInitializer;
CCottageApplication cottage("Maze", 1200, 750);

int main()
{
    cottage.MainLoop();
}