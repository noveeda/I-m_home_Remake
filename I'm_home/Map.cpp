#include "Map.h"

void InitMap() { 
	for (int i = 0; i < MAP_SIZE; i++) 
		memset(front_map[i], (int)Object_Type::NONE, MAP_SIZE); }


void UpdateMap() {

}