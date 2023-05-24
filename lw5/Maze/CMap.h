#include "CWall.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "GL/glut.h"

#pragma once
class CMap
{
public:
	CMap(std::string mazeStructureFileName);
	void DrawWalls();
	bool CheckWall(int cZ, int cX);
private:
	std::vector<std::vector<char>> m_mapStructure;
	const float m_cubeSize = 2;
	void WriteMaze(std::string mazeStructureFileName);
	void DrawChunk(float cx, float cy, float cz) const;
};
