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
	int area[MAX_AREA_SIZE][MAX_AREA_SIZE] = { -1 };
	//for (int i = 0; i < MAX_AREA_SIZE; ++i) // Set all field to -1 representing thet isn't part of the active area.
	//{
	//	for (int j = 0; j < MAX_AREA_SIZE; ++j)
	//	{
	//		area[i][j] = -1;
	//	}
	//}

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
		int currentX = territorys[i].posX;
		int currentY = territorys[i].posY;
		int endX = currentX + territorys[i].size;
		int endY = currentY + territorys[i].size;
		for (int j = currentX; j <= endX; ++j)
		{
			for (int k = currentY; k < endY; k++)
			{
				area[j][k] = 1;
			}
		}
	}

	cout << "Hello World!\n";
	return 0;
}