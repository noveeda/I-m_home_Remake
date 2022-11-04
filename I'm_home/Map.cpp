#include "Map.h"

void InitMap() { 
	for (int i = 0; i < MAP_SIZE; i++) 
		memset(front_map[i], (int)Object_Type::NONE, MAP_SIZE); }


void UpdateMap() {

}

/// <summary>
/// Ãâ·Â
/// </summary>
/// <param name="map"></param>
/// <param name="front_map"></param>
void RenderMap(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}