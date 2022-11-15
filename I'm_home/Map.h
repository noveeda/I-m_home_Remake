#include "Utils.h"

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

static char front_map[MAP_SIZE][MAP_SIZE];


void InitMap();

void RenderMap(char map[MAP_SIZE][MAP_SIZE], char front_map[MAP_SIZE][MAP_SIZE]);