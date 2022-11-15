#pragma once

#define MAP_SIZE	10

extern char map[MAP_SIZE][MAP_SIZE];

extern char front_map[MAP_SIZE][MAP_SIZE];

typedef enum class Object_Type {
	NONE = 0,
	STREET,
	WALL,
	DRUNKEN,
	COP,
	PUB,
	HOME
}Object_Type;

typedef enum class Direction {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
}Direction;

typedef enum class Colors {
	BLACK		,
	DARK_BLUE	,
	GREEN		,
	BLUE_GREEN	,
	BLOOD		,
	PURPLE		,
	GOLD		,
	ORIGINAL	,
	GRAY		,
	BLUE		,
	HIGH_GREEN	,
	SKY_BLUE	,
	RED			,
	PLUM		,
	YELLOW		,
	WHITE	
}Colors;

