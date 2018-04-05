#include "Target.h"

Target::Target(Room * room, int x, int y): Object(room, false, x, y) {}

bool Target::OverlapsWith(Object * other)
{
	(void)other;
	return true;
}
