#include "Value.h"
#include "Utils.h"

void PrintScreen(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]) {
	
	for (int i = 0; i < MAP_SIZE; i++) 
		for (int j = 0; j < MAP_SIZE; j++) 
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}

void Awake() {
	CursorSettings(false);
}

int main() {
	static char map[MAP_SIZE][MAP_SIZE] = { 
		1,2,2,1,2,2,1,1,1,1,
		1,1,1,1,1,1,2,1,2,2,
		1,1,1,1,1,1,2,1,2,1,
		1,2,2,1,2,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,2,2,2,2,1,2,1,2,1,
		1,1,1,1,1,1,2,1,1,1,
		1,2,2,1,2,1,2,1,2,1,
		1,1,1,1,1,1,1,1,1,1
	};
	static char front_map[MAP_SIZE][MAP_SIZE] = { NONE };

	PrintScreen(map, front_map);
	map[0][0] = 2;
	_getch();
	PrintScreen(map, front_map);
}