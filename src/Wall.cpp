#include "Wall.h"

Wall::Wall(Room * room, int x, int y): Object(room, false, x, y) {}

bool Wall::OverlapsWith(Object * other)
{
	(void)other;
	return false;
}
