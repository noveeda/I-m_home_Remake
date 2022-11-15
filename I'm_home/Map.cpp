#include "Map.h"

/// <summary>
/// 맵 초기화
/// </summary>
void InitMap() { 
	for (int i = 0; i < MAP_SIZE; i++) 
		memset(front_map[i], (char)Object_Type::NONE, MAP_SIZE); 
}

/// <summary>
/// 맵 출력
/// </summary>
/// <param name="map">변경된 맵 데이터</param>
/// <param name="front_map">변경 이전 데이터</param>
void RenderMap(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}