#include "Utils.h"

typedef struct Entity {
	int x;
	int y;

	void operator = (COORD pos) {
		x = pos.X;
		y = pos.Y;
	}
	void operator += (COORD pos) {
		x += pos.X;
		y += pos.Y;
	}
	void operator -= (COORD pos) {
		x -= pos.X;
		y -= pos.Y;
	}
}Entity;

void Move(Entity& entity, char map[MAP_SIZE][MAP_SIZE], bool isAuto);