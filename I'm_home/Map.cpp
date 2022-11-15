#include "Map.h"

extern char map[MAP_SIZE][MAP_SIZE];

/// <summary>
/// �� ���
/// </summary>
/// <param name="map">����� �� ������</param>
/// <param name="front_map">���� ���� ������</param>
void RenderMap() {
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}