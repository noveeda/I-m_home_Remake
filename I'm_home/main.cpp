#include "Value.h"
#include "Utils.h"

// �ùķ��̼� ȭ�� ���
void PrintScreen(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]) {
	for (int i = 0; i < MAP_SIZE; i++) 
		for (int j = 0; j < MAP_SIZE; j++) 
			if (map[i][j] != front_map[i][j]) {
				DrawChar(j, i, map[i][j]);
				front_map[i][j] = map[i][j];
			}
	gotoxy(0, 11);
}

// ���α׷� �ʱ�ȭ
void Awake() {
	CursorSettings(false);
}

// ����
int main() {

}