#include "Target.h"
#include "Box.h"

Box::Box(Room * room, int x, int y): Object(room, true, x, y) {}

bool Box::OverlapsWith(Object * other)
{
	if (dynamic_cast<Target *>(other))
	{
		return true;
	}
	else
	{
		return false;
	}
}
