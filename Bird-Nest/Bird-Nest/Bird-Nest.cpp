#include <iostream>

using namespace std;

struct Teritory
{
	int posX;
	int posY;
	int size;
};

int main()
{
	const int MAX_AREA_SIZE = 100;
	const int MAX_BIRD_NESTS = 32;
	int birdCount = 0;
	int areaSize = 0;
	Teritory territorys[MAX_BIRD_NESTS];
	int area[MAX_AREA_SIZE][MAX_AREA_SIZE];

	for (int i = 0; i < MAX_AREA_SIZE; ++i) // Set all field to -1 representing thet isn't part of the active area.
	{
		for (int j = 0; j < MAX_AREA_SIZE; ++j)
		{
			area[i][j] = -1;
		}
	}

	cin >> birdCount >> areaSize;

	for (int i = 0; i < areaSize; ++i) // Set the active areas to 0 representing that there are no bird territory.
	{
		for (int j = 0; j < areaSize; ++j)
		{
			area[i][j] = 0;
		}
	}

	for (int i = 0; i < birdCount; ++i)
	{
		cin >> territorys[i].posX >> territorys[i].posY >> territorys[i].size;
	}

	for (int i = 0; i < birdCount; ++i)
	{
		int currentNestX = territorys[i].posX - 1;
		int currentNestY = territorys[i].posY - 1;
		int startTerritoryX = currentNestX - territorys[i].size;
		int startTerritoryY = currentNestY - territorys[i].size;
		int endTerritoryX = currentNestX + territorys[i].size;
		int endTerritoryY = currentNestY + territorys[i].size;
		for (int j = startTerritoryX; j <= endTerritoryX; ++j)
		{
			for (int k = startTerritoryY; k <= endTerritoryY; k++)
			{
				if (j >= 0 && k >= 0 && j < areaSize && k < areaSize)
				{
					area[j][k] = 1;
				}
			}
		}
		area[currentNestX][currentNestY] = 2;
	}

	int emptyFieldCount = 0;
	for (int i = 0; i < areaSize; ++i)
	{
		for (int j = 0; j < areaSize; ++j)
		{
			if (area[i][j] == 0)
			{
				++emptyFieldCount;
			}
		}
	}
	cout << emptyFieldCount;
	return 0;
}