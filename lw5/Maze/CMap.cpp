#include "CMap.h"

CMap::CMap(std::string mazeStructureFileName)
{
	WriteMaze(mazeStructureFileName);
}

void CMap::WriteMaze(std::string mazeStructureFileName)
{
	std::ifstream mazeStructureStream(mazeStructureFileName);
	if (!mazeStructureStream.is_open())
	{
		throw(!"Failed to open file");
		return;
	}

	std::string line = "";
	size_t vectorSize = 0;
	while (getline(mazeStructureStream, line))
	{

		m_mapStructure.push_back(std::vector<char>());
		std::stringstream charsLineStream(line);
		char c;
		while (charsLineStream >> c)
		{
			m_mapStructure[vectorSize].push_back(c);
		}
		vectorSize++;
	}
}


void CMap::DrawChunk(float cx, float cy, float cz) const
{
	CWall cube = CWall(cx, cy, cz);
	cube.SetSideColor(CWall::CS_NEGATIVE_X, 255, 0, 0);
	cube.SetSideColor(CWall::CS_POSITIVE_X, 0, 255, 0);
	cube.SetSideColor(CWall::CS_NEGATIVE_Y, 0, 0, 255);
	cube.SetSideColor(CWall::CS_POSITIVE_Y, 255, 255, 0);
	cube.SetSideColor(CWall::CS_NEGATIVE_Z, 0, 255, 255);
	cube.SetSideColor(CWall::CS_POSITIVE_Z, 255, 0, 255);
	cube.Draw();
}

void CMap::DrawWalls()
{
	const float y = 0;
	int z = 0;
	for (size_t i = 0; i < m_mapStructure.size(); i++)
	{
		std::vector<char> line = m_mapStructure[i];
		int x = 0;
		for (size_t j = 0; j < m_mapStructure.size(); j++)
		{
			if (line[j] == '#')
			{
				DrawChunk(x, y, z);
			}
			DrawChunk(x, y - m_cubeSize, z);
			x += 2;
		}
		z += 2;
	}
}

bool CMap::CheckWall(int cZ, int cX)
{
	if (m_mapStructure[cZ][cX] == '#')
	{
		return true;
	}
	return false;
}
