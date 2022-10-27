#include <stdio.h>

#define MAP_SIZE	10

typedef enum Object_Type {
	NONE,
	STREET,
	WALL,
	DRUNKEN,
	COP,
	PUB,
	HOME
}Object_Type;

#define DEFAULT		7
#define DARK_GRAY	8
#define GREEN		10
#define RED			12
#define PINK		13
#define YELLOW		14
#define WHITE		15