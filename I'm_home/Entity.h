#include "Utils.h"

typedef struct Entity {
	Object_Type entity_type;
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

Entity GenerateEntity(int quad, Object_Type obj_type);

void Move(Entity& entity, bool isAuto);