#include "Game.h"

// Ω√¿€
int main() {
	srand(time(NULL));
	//map[0][0] = (char)Object_Type::DRUNKEN;
	Entity p = GenerateEntity(1, Object_Type::DRUNKEN);

	RenderMap();
}