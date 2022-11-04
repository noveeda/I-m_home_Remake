#include "Utils.h"

typedef struct Entity {
	int x;
	int y;

	void operator = (COORD pos) {
		x = pos.X;
		y = pos.Y;
	};

	void operator += (COORD pos) {
		x += pos.X;
		y += pos.Y;
	}

	void operator -= (COORD pos) {
		x -= pos.X;
		y -= pos.Y;
	}
}Entity;

bool Move(char map[MAP_SIZE]);