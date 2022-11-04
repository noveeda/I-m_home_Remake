#include "Value.h"
#include "Utils.h"

// 시뮬레이션 화면 출력
void PrintScreen(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++) 
		for (int j = 0; j < MAP_SIZE; j++) 
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}

// 프로그램 초기화
void Awake() {
	CursorSettings(false);
}

// 시작
int main() {

}